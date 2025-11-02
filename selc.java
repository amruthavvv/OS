import java.net.*;
import java.io.*;
import java.util.Random;

public class client {
    static Socket connection;

    public static void main(String a[]) {
        try {
            int[] v = new int[10];
            int n = 0;
            Random rands = new Random();
            int rand;

            InetAddress addr = InetAddress.getByName("localhost");
            System.out.println(addr);

            connection = new Socket(addr, 8011);
            DataOutputStream out = new DataOutputStream(connection.getOutputStream());
            DataInputStream in = new DataInputStream(connection.getInputStream());

            int p = in.readInt();
            System.out.println("No of frames: " + p);

            if (p <= 0) {
                System.out.println("No frames received. Exiting...");
                connection.close();
                return;
            }

            for (int i = 0; i < p; i++) {
                v[i] = in.readInt();
                System.out.println("Frame " + (i + 1) + ": " + v[i]);
            }

            rand = rands.nextInt(p);
            v[rand] = -1;

            for (int i = 0; i < p; i++) {
                System.out.println("Received frame is: " + v[i]);
            }

            for (int i =
