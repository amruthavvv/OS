import java.net.*;
import java.io.*;
public class server
{
  public static void main(String[]args)throws Exception
  {
    System.out.println("Waiting for client....");
    ServerSocket ss=new ServerSocket(8888);
    Socket s=ss.accept();
    System.out.println("connected client....");
    DataInputStream din=new DataInputStream(s.getInputStream());
    DataOutputStream dout=new DataOutputStream(s.getOutputStream());
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Waiting for client message...");
    String s1=din.readUTF();
    System.out.println("client:"+s1);
    System.out.println("enter the message to client..");
    String s2=br.readLine();
    dout.writeUTF(s2);
    dout.flush();
    s.close();
    ss.close();
 }
}
