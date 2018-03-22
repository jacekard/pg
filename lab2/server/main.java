import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class main {
    public static void main(String[] args) throws IOException {

        ExecutorService executor = Executors.newFixedThreadPool(5);

        try (ServerSocket serverSocket = new ServerSocket(Server.port)) {
            while (true) {
                try {
                    final Socket socket = serverSocket.accept();
                    executor.submit(() -> {
                        try {
                            Server.receiveFile(socket);
                        } catch (IOException e) {
                            System.out.println("Problem during the download: " + e.getMessage());
                        }
                    });
                } catch (IOException e) {
                    System.out.println("There's some problem with accepting new clients.");
                    System.exit(1);
                }
            }
        }

    }
}
