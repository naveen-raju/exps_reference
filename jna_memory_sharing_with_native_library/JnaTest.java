//package com.hp.storage.pml.file.disasterrecovery.impl.rpc;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.Library;
import com.sun.jna.Memory;
import com.sun.jna.Native;
import java.util.List;
import java.util.Arrays;

/*
public class BigData extends Structure {
    public int len;
    public Pointer data;

    protected List getFieldOrder() {
        return Arrays.asList("len", "data");
    }

}
*/

/** Simple example of native library declaration and usage. */
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
        netobj.data = new Memory(256 * 2);
        netobj.len = 1;
        netobj.data.setString(0, "Test : First String ");
        netobj.data.setString(256, "Test : Second String");
        INSTANCE.print_data(netobj);
    }
}
