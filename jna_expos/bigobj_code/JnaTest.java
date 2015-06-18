//package com.hp.storage.pml.file.disasterrecovery.impl.rpc;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.Library;
import com.sun.jna.Memory;
import com.sun.jna.Native;
import java.util.List;
import java.util.Arrays;

public class JnaTest {
    
    public interface CLibrary extends Library {

        /**
         *
         * @param data
         */
        void print_data(BigData data);
    }
    
    
 
    public static void main(String[] args) {
        CLibrary INSTANCE = (CLibrary) Native.loadLibrary("/home/bigobj_code/clib/libhello.so", CLibrary.class);
        //Native.setProtected(true);
        
        System.out.println("Inside main");
        BigData netobj = new BigData();
        netobj.data = new Memory(256 * 2 * 2);
        netobj.len = 2;
        int offset = 0;
        netobj.data.setString(offset, "Testdata1 : First String");
        offset = offset + 256;
        netobj.data.setString(offset, "Testdata1 : Second String");
        offset = offset + 256;
        netobj.data.setString(offset, "Testdata2 : Random first String");
        offset = offset + 256;
        netobj.data.setString(offset, "Testdata2 : Random second String");

        INSTANCE.print_data(netobj);

        try {
                Thread.sleep(10000);                 //1000 milliseconds is one second.
        } catch(Exception ex) {
               // Thread.currentThread().interrupt();
        }
    }
}
