package sample;

import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.File;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Controller {
    @FXML
    private Label statusLabel;
    @FXML
    private ProgressBar progressBar;
    private ExecutorService executor = Executors.newSingleThreadExecutor();

    @FXML
    public void chooseFile(ActionEvent event) {
        FileChooser chooser = new FileChooser();
        chooser.setTitle("Open File");
        File file = chooser.showOpenDialog(new Stage());

        if (file == null) return;
        try {
            Task<Void> sendFileTask = new SendFileTask(file);
            statusLabel.textProperty().bind(sendFileTask.messageProperty());
            progressBar.progressProperty().bind(sendFileTask.progressProperty());
            executor.submit(sendFileTask);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
