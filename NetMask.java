import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Netmask
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Short prefix = 0;
        String netmask = args[0];
        String[] octets = netmask.split("\\.");

        for (String each: octets) {
            for (int x = Integer.parseInt(each); x > 0 ; x = x & (x- 1)) {
                prefix++;
                System.out.println("each:" + each + ",x:" + x + ",prefix:" + prefix);
            }
        }
        System.out.print("Netmask: " + netmask + ",prefix:" + prefix);
    }
}
