package application;

import java.util.concurrent.TimeUnit;

import controllers.UIController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * This class represent the Main class of the JavaFX-based application.
 */
public final class Main extends Application {

    private static final int SCENE_WIDTH = 1400;
    private static final int SCENE_HEIGHT = 900;
    
    private UIController UIController; 
    

    @Override
    public void start(final Stage stage) throws Exception {
        //final Parent root = FXMLLoader.load(ClassLoader.getSystemResource("layouts/main.fxml"));
        
        FXMLLoader loader = new FXMLLoader(ClassLoader.getSystemResource("layouts/main.fxml")); 
        Parent root = loader.load(); 
        UIController = (UIController) loader.getController(); 
        final Scene scene = new Scene(root, SCENE_WIDTH, SCENE_HEIGHT);
        UIController.init();
        
//        final FXMLLoader loader = new FXMLLoader();
//        final Scene scene = new Scene(loader.load(getClass().getResourceAsStream("layouts/main.fxml")));
//        this.uiController = loader.getController();
        
        stage.setTitle("JavaFX - Complete Example");
        stage.setScene(scene);
        stage.show();
        for(int i = 0; i < 40; i++) {
        	this.UIController.addData(i, 20+i, 10+1, i/(float)100);
        }
    }

    /**
     * 
     * @param args unused
     */
    public static void main(final String[] args) {
        launch();
    }

}
