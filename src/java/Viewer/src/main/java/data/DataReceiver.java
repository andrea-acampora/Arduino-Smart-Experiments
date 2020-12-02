package data;

import serial.CommChannel;
import serial.SerialCommChannel;

public class DataReceiver {

    private CommChannel channel;
    private ExperimentData data;


    public DataReceiver(final CommChannel channel) throws Exception {
        this.channel = channel;
        this.data = new ExperimentData();
    }

    public CommChannel getCommChannel() {
    	return this.channel;
    }
    
    public final boolean recive() throws InterruptedException {
          String msg = channel.receiveMsg();
          this.extractData(msg);
          return true;
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
    
    public ExperimentData getExperimentData() {
    	return this.data;
    }
}
