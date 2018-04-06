package sample;

import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.control.cell.ProgressBarTableCell;
import javafx.stage.DirectoryChooser;
import javafx.stage.FileChooser;

import java.io.File;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.ResourceBundle;
import java.util.concurrent.ForkJoinPool;

public class Controller implements Initializable {
    @FXML TableColumn<ImageProcessingJob, String> imageNameColumn;
    @FXML TableColumn<ImageProcessingJob, Double> progressColumn;
    @FXML TableColumn<ImageProcessingJob, String> statusColumn;
    @FXML Button processButton;
    @FXML Button selectFilesButton;
    @FXML Button selectDirectoryButton;
    @FXML Button threadModeChooserButton;
    @FXML Label statusLabel;
    @FXML TableView imagesTableView;

    public File targetDirectory = null;
    public int threadMode = 0;
    private long start, end;
    private boolean hasFinished = false;
    private List<File> selectedFiles;
    ObservableList<ImageProcessingJob> jobs;
    ForkJoinPool pool;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        //nazwa pliku
        imageNameColumn.setCellValueFactory( p -> new SimpleStringProperty(p.getValue().getFile().getName()));
        //status przetwarzania
        statusColumn.setCellValueFactory(p -> p.getValue().getStatusProperty());
        //wykorzystanie paska postępu
        progressColumn.setCellFactory(ProgressBarTableCell.<ImageProcessingJob>forTableColumn());
        //postęp przetwarzania
        progressColumn.setCellValueFactory(p -> p.getValue().getProgressProperty().asObject());
       // ...dalsze inicjalizacje...

        jobs = FXCollections.observableList(new ArrayList<>());
        imagesTableView.setItems(jobs);
        pool = new ForkJoinPool(1);
    }

    @FXML
    void directoryLoadChooserAction(ActionEvent event) {
        if (targetDirectory == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setHeaderText("Uwaga!");
            alert.setContentText("Wybierz folder do zapisu!");
            alert.showAndWait();

            return;
        }

        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().add(
                new FileChooser.ExtensionFilter("JPG images", "*.jpg"));
        selectedFiles = fileChooser.showOpenMultipleDialog(null);

        jobs.clear();
        selectedFiles.stream().forEach(f -> jobs.add(new ImageProcessingJob(f, targetDirectory)));
        statusLabel.setText("Wybrano " + selectedFiles.size() + " pliki");
    }

    @FXML
    void directorySaveChooserAction(ActionEvent event) {
        DirectoryChooser directoryChooser = new DirectoryChooser();
        targetDirectory = directoryChooser.showDialog(null);
    }


    //metoda obsługująca kliknięcie przycisku rozpoczynającego przetwarzanie
    @FXML
    void processFiles(ActionEvent event) {

        if(hasFinished) {
            jobs.clear();
            selectedFiles.stream().forEach(f -> jobs.add(new ImageProcessingJob(f, targetDirectory)));
        }
        start = System.currentTimeMillis(); //zwraca aktualny czas [ms]
        new Thread(this::backgroundJob).start();
        Platform.runLater(() -> {
            statusLabel.setText("Przetwarzanie...");
        });


    }

    @FXML
    void updateTimer() {
        Platform.runLater(() -> {
                    double end = (System.currentTimeMillis() - start) / 1000.0;
                    statusLabel.setText("Gotowe! Czas: " + end + "s.");
                    hasFinished = true;
                });
    }

    //metoda uruchamiana w tle (w tej samej klasie)
    @FXML
    private void backgroundJob(){
         jobs.stream().forEach( j -> pool.submit(j));

         jobs.stream().forEach(j -> {
             while(!j.getStatusProperty().getValue().equals("Zakończone")) {
                 System.out.print("");
             }
         });

        updateTimer();

    }

    @FXML
    private void threadModeSequence(ActionEvent event) {
        threadMode = 0;
        changeProcessingMode();
    }
    @FXML
    private void threadModeCommonPool(ActionEvent event) {
        threadMode = 1;
        changeProcessingMode();
    }
    @FXML
    private void threadModeChosenPool(ActionEvent event) {
        threadMode = 2;
        changeProcessingMode();
    }

    private void changeProcessingMode() {
        switch(threadMode) {
            case 0:
                pool = new ForkJoinPool(1);

                break;
            case 1:
                pool = new ForkJoinPool();

                break;

            case 2:
                TextInputDialog dialog = new TextInputDialog("2");
                dialog.setTitle("Wybór wątków");
                dialog.setContentText("Wybierz ilość wątków:");
                Optional<String> result = dialog.showAndWait();
                String entered;
                int count = 1;
                if (result.isPresent()) {
                    entered = result.get();
                    count = Integer.parseInt(entered);
                }
                pool = new ForkJoinPool(count);
        }
    }
}
