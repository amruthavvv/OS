import java.net.*;
import java.io.*;
import java.util.Random;
public class gobc
 {
  public static void main(String args[]) throws Exception
   {
    Socket s = new Socket("localhost", 8088);
    DataInputStream din = new DataInputStream(s.getInputStream());
    DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    int frames[] = new int[20];
    int n = din.read();
    System.out.println("Number of frames received: " + n);
    for (int i = 0; i < n; i++)
     {
      frames[i] = din.read();
      System.out.println("Received frame " + i + ": " + frames[i]);
     }
    Random r = new Random();
    int lost = r.nextInt(n);
    System.out.println("\nFrame " + lost + " lost during transmission!");       
    dout.write(lost);
    dout.flush();      
    System.out.println("\nReceiving retransmitted frames...");
    for (int i = lost; i < n; i++)
     {
      frames[i] = din.read();
      System.out.println("Received frame " + i + ": " + frames[i]);
     }
    System.out.println("\nAll frames received successfully!");
    dout.close();
    din.close();
    s.close();
  }
 }
