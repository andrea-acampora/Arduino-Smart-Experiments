package application;

import data.DataReceiver;
import serial.CommChannel;
import serial.SerialCommChannel;

/**
 * This class represents the Launcher of the system, to bypass JAVA 11 modules constraints.
 */
public final class Launcher {

    private Launcher() { }

    /**
     * @param args unused
     * @throws Exception 
     */
    public static void main(final String[] args) throws Exception {
        Main.main(args);
    }
}
