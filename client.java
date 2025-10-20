import java.net.*;
import java.io.*;
public class client
{
  public static void main(String[]args)throws Exception
  {
   System.out.println("client started...");
   Socket s=new Socket("localhost",8888);
   DataInputStream din=new DataInputStream(s.getInputStream());
   DataOutputStream dout=new DataOutputStream(s.getOutputStream());
   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   System.out.println("enter a message....");
   String s1=br.readLine();
   dout.writeUTF(s1);
   dout.flush();
   System.out.println("Waiting for server reply...");
   String s2=din.readUTF();
   System.out.println("server says...:"+s2);
   din.close();
   dout.close();
 }
}
