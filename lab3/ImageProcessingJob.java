package sample;

import javafx.application.Platform;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.concurrent.Task;
import javafx.scene.control.Alert;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ImageProcessingJob extends Task<Void> {
    public File sourceFile;
    public File targetDirectory;
    public SimpleStringProperty status;
    public DoubleProperty progress;

    public ImageProcessingJob(File file, File targetDirectory) {
        sourceFile = file;
        status = new SimpleStringProperty("Oczekiwanie");
        progress = new SimpleDoubleProperty(0);
        if(targetDirectory != null) {
            this.targetDirectory = targetDirectory;
        }
    }

    public File getFile() {
        return sourceFile;
    }

    public SimpleStringProperty getStatusProperty() {
        return status;
    }

    public DoubleProperty getProgressProperty() {
        return progress;
    }

    public void setProgressProperty(int value) {
        progress.set(0);
    }

    public void setStatusProperty(String v) {
        status.set(v);
    }

    //oryginalny plik graficzny, katalog docelowy, własność określająca postęp operacji
    private void convertToGrayscale(File originalFile, File outputDir, DoubleProperty progressProp) {
        try {
            //wczytanie oryginalnego pliku do pamięci
            BufferedImage original = ImageIO.read(originalFile);
            status.set("Przetwarzanie");
            //przygotowanie bufora na grafikę w skali szarości
            BufferedImage grayscale = new BufferedImage(original.getWidth(), original.getHeight(), original.getType());
            //przetwarzanie piksel po pikselu
            for (int i = 0; i < original.getWidth(); i++) {
                for (int j = 0; j < original.getHeight(); j++) {
                    //pobranie składowych RGB
                    int red = new Color(original.getRGB(i, j)).getRed();
                    int green = new Color(original.getRGB(i, j)).getGreen();
                    int blue = new Color(original.getRGB(i, j)).getBlue();
                    //obliczenie jasności piksela dla obrazu w skali szarości
                    int luminosity = (int) (0.21*red + 0.71*green + 0.07*blue);
                    //przygotowanie wartości koloru w oparciu o obliczoną jaskość
                    int newPixel = new Color(luminosity, luminosity, luminosity).getRGB();
                    //zapisanie nowego piksela w buforze
                    grayscale.setRGB(i, j, newPixel);
                }
                //obliczenie postępu przetwarzania jako liczby z przedziału [0, 1]
                double progress = (1.0 + i) / original.getWidth();
                //aktualizacja własności zbindowanej z paskiem postępu w tabeli
                Platform.runLater(() -> progressProp.set(progress));
            }
            //przygotowanie ścieżki wskazującej na plik wynikowy
            Path outputPath = Paths.get(outputDir.getAbsolutePath(), originalFile.getName());

            //zapisanie zawartości bufora do pliku na dysku
            ImageIO.write(grayscale, "jpg", outputPath.toFile());
        } catch (IOException ex) {
            //translacja wyjątku
            throw new RuntimeException(ex);
        }

        status.set("Zakończone");
    }

    @Override
    protected Void call() throws Exception {
            progress.set(0);
            status.set("Oczekiwanie");
            convertToGrayscale(sourceFile, targetDirectory, progress);
            return null;
    }
}
