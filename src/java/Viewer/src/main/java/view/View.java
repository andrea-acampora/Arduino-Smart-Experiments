package view;

import java.io.IOException;

import controllers.Controller;
import controllers.Loop;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class View {
	
    private static final int SCENE_WIDTH = 1400;
    private static final int SCENE_HEIGHT = 900;
    private UIController uiController;
    private Controller controller;
    private final Stage stage;

	public View(final Stage stage) throws IOException {
		this.stage = stage;
	}
	

	public UIController getUIController() {
		return this.uiController;
	}
	
	public void launch(final Controller controller) throws IOException {
		this.controller = controller;
        FXMLLoader loader = new FXMLLoader(ClassLoader.getSystemResource("layouts/main.fxml")); 
        Parent root = loader.load(); 
        uiController = (UIController) loader.getController(); 
        final Scene scene = new Scene(root, SCENE_WIDTH, SCENE_HEIGHT);
        uiController.init(controller);
        stage.setTitle("JavaFX - Complete Example");
        stage.setScene(scene);
        stage.show();
	}
	
	
	
}
