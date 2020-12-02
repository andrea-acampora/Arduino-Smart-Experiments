package application;

import controllers.Controller;
import controllers.Loop;
import data.DataReceiver;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import serial.CommChannel;
import serial.SerialCommChannel;
import view.UIController;
import view.View;

/**
 * This class represent the Main class of the JavaFX-based application.
 */
public final class Main extends Application {
     

    @Override
    public void start(final Stage stage) throws Exception {
        CommChannel channel = new SerialCommChannel("/dev/ttyACM1",9600);
	    DataReceiver receiver = new DataReceiver(channel);
    	View view = new View(stage);
	    Controller controller = new Controller(view,receiver);
    	view.launch(controller);
    	controller.start();
    }

    /**
     * 
     * @param args unused
     * @throws Exception 
     */
    public static void main(final String[] args) throws Exception {
        launch();
    }

}
