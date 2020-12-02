package controllers;

import data.DataReceiver;
import javafx.application.Platform;
import view.View;

public class Loop extends Thread {
	
	private View view;
	private DataReceiver receiver;
    private Thread thread;

	
	public Loop(final View view, final DataReceiver receiver) {
        this.setDaemon(true);
		this.view = view;
		this.receiver = receiver;
	}
	
	public final void start() {
		this.thread = new Thread(this, "GuiThread");
		this.thread.start();
	}
	
	public final void run(){
		while (true) {
			try {
				if (this.receiver.recive()) {
				    Platform.runLater(() -> this.view.getUIController().update(this.receiver.getExperimentData()));
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
