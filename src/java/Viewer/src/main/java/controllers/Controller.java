package controllers;

import data.DataReceiver;
import view.View;

public class Controller {

	Loop loop;
	private View view;
	private DataReceiver receiver;
	
	
	public Controller(final View view , final DataReceiver receiver) {
		this.view = view;
		this.receiver = receiver;
		this.loop = new Loop(view, receiver);
	}
	
	public final void reportOkPressed() {
		this.receiver.getCommChannel().sendMsg("OK");
	}
	
	public void start() {
		this.loop.start();
	}
	
}
