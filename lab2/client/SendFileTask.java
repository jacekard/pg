package sample;

import javafx.concurrent.Task;

import java.io.*;
import java.net.Socket;

public class SendFileTask extends Task<Void> {
    public File file; //plik do wysłania
    public Socket socket = null;
    public String host = "192.168.43.16";
    public int bytesRead;
    public Boolean success;
    public SendFileTask(File file) {
        this.file = file;
    }
    @Override protected Void call() throws Exception {

        success = false;
        updateMessage("Connecting...");
        DataOutputStream out = null;
        FileInputStream in = null;
        try {
            socket = new Socket(host, 2222);
            if(!socket.isConnected()) {
                updateMessage("Failed to connect to the server");
                updateProgress(100, 100);
                return null;
            }
            in = new FileInputStream(file);
            out = new DataOutputStream(socket.getOutputStream());

            updateProgress(0, file.length());

            out.writeUTF(file.getName());
            out.writeLong(file.length());
            int readBuff = 0;
            byte[] buffer = new byte[512];
            while ((readBuff = in.read(buffer)) > 0) {
                out.write(buffer, 0, readBuff);
                bytesRead += readBuff;
                updateProgress(bytesRead, file.length());
            }
            success = true;
            updateMessage("Received!");
            updateProgress(file.length(), file.length());
        } catch(Exception e) {
            e.printStackTrace();
            updateMessage("There's some problem with uploading");
        } finally {
            if(socket != null) socket.close();
            if(in != null) in.close();
            if(out != null) out.close();
        }
        if(success == false)
            updateMessage("Failed!");


        return null;
    }
}
