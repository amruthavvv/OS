import java.net.*;
import java.io.*;
public class gobs
 {
  public static void main(String args[]) throws IOException 
   {
    ServerSocket ss = new ServerSocket(8088);
    Socket s = ss.accept();
    DataInputStream din = new DataInputStream(s.getInputStream());
    DataOutputStream dout = new DataOutputStream(s.getOutputStream());
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int frames[] = new int[20];
    System.out.print("Enter number of frames to send: ");
    int n = Integer.parseInt(br.readLine());
    System.out.println("Enter " + n + " frame values:");
    for(int i = 0; i < n; i++) 
     {
      frames[i] = Integer.parseInt(br.readLine());
     }
    System.out.println("Sending " + n + " frames...");
    dout.write(n); 
    dout.flush();
    for(int i = 0; i < n; i++) 
     {
      dout.write(frames[i]); 
      dout.flush();
      System.out.println("Frame " + i + " sent: " + frames[i]);
     }
    int lost = din.read(); 
    System.out.println("Client reported loss at frame number: " + lost);
    System.out.println("Resending from frame " + lost + " onwards...");
    for(int i = lost; i < n; i++)
     {
      dout.write(frames[i]);
      dout.flush();
      System.out.println("Resent frame " + i + ": " + frames[i]);
     }
     din.close();
    dout.close();
    s.close();
    ss.close();
   }
 }
 
