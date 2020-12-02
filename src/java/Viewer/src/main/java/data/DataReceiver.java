package data;

import serial.CommChannel;
import serial.SerialCommChannel;

public class DataReceiver {

    private CommChannel channel;
    private ExperimentData data;
    private static final String SERIALPORT = "/dev/ttyACM1";
    private static final int BITRATE = 9600;

    public DataReceiver() throws Exception {
        this.channel = new SerialCommChannel(SERIALPORT, BITRATE);
        this.data = new ExperimentData();
        Thread.sleep(4000);
    }

    public final void recive() throws InterruptedException {

        while (true) {
          String msg = channel.receiveMsg();
          this.extractData(msg);
        }
    }

    private void extractData(final String msg) {
    	final String STATE_PATTERN = "State=";
        final String POS_PATTERN = "Pos=";
        final String SPEED_PATTERN = "Speed=";
        final String ACC_PATTERN = "Acc=";

        if (msg.contains(STATE_PATTERN)) {
        	String state = msg.replaceAll(STATE_PATTERN, "");
        	data.setState(state);
        } else if (msg.contains(POS_PATTERN)) {
        	Double pos = Double.parseDouble(msg.replaceAll(POS_PATTERN, ""));
        	data.addPosition(pos);
        } else if (msg.contains(SPEED_PATTERN)) {
        	Double speed = Double.parseDouble(msg.replaceAll(SPEED_PATTERN, ""));
        	data.addSpeed(speed);
        } else if (msg.contains(ACC_PATTERN)) {
        	Double acc = Double.parseDouble(msg.replaceAll(ACC_PATTERN, ""));
        	data.addAcceleration(acc);
        }
	}
}
