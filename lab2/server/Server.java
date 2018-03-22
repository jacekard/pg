import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;


public class Server {
    public static int port = 2222;
    public static ServerSocket serverSocket = null;

    public static void receiveFile(Socket client) throws IOException {
        long fileSize = 0;
        String fileName = "";
        try(DataInputStream in = new DataInputStream(client.getInputStream())) {
            try {
                fileName = in.readUTF();
                fileSize = in.readLong();
            } catch (Exception e) {
                e.printStackTrace();
            }

            File file = new File(".", fileName);

            file.createNewFile();
            FileOutputStream out = new FileOutputStream(file);
            try {
                int bytesRead = 0, readBuff = 0;
                byte[] buffer = new byte[512];

                while (bytesRead < fileSize) {
                    readBuff = in.read(buffer);

                    if (readBuff != -1) bytesRead += readBuff;
                    else throw new IOException("Couldn't read the entire file!");

                    out.write(buffer, 0, readBuff);
                }

                System.out.println(fileName + " was downloaded!");
                out.close();
            } catch (IOException e) {
                System.out.println("Error while reading " + fileName +
                        ", error reported: " + e.getMessage());
                file.delete();
            }
            client.close();
        }
    }
}
