package controllers;

import javafx.fxml.FXML;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.Slider;
import javafx.scene.layout.AnchorPane;

/**
 * The Controller related to the main.fxml GUI.
 *
 */
public final class UIController {

	@FXML
	private NumberAxis xAxys; 
	
    @FXML
    private Label stateLabel;
    
    @FXML
    private ProgressBar objectPosition; 
    
    @FXML
    private LineChart<Number, Number> lineChart; 
    
    @FXML
    private AnchorPane overPane; 

    
    XYChart.Series<Number,Number> speed;
    XYChart.Series<Number,Number> acceleration; 
    
    @FXML
    public void OKPressed() {
    	//aggiungere funzione per mandare alla seriale l'ok
    }
    
    public void init() {
    	this.speed = new XYChart.Series<>();
    	this.acceleration = new XYChart.Series<>();
    	this.speed.setName("speed");
    	this.acceleration.setName("acceleration");
    	this.lineChart.getData().add(speed); 
    	this.lineChart.getData().add(acceleration); 
    	this.overPane.setVisible(false);     	
    }
    
    public void addData(int i, float speedData, float accelerationData, float objectPosition) {
    	this.checUpperBound(i); 
		this.speed.getData().add(new XYChart.Data<Number, Number>(i, speedData)); 
		this.acceleration.getData().add(new XYChart.Data<Number, Number>(i, accelerationData)); 
		this.objectPosition.setProgress(objectPosition);
    }
    
    private void checUpperBound(int i) {
		if (this.xAxys.getUpperBound() == i) {
			this.xAxys.setUpperBound(this.xAxys.getUpperBound() * 2);
		}
	}

	public void setState(String state) {
    	this.stateLabel.setText(state);
 
    }
    
    private void clearChart() {
    	this.lineChart.getData().clear();
    }
    
    public void showButton() {
    	this.clearChart();
    	this.overPane.setVisible(true);
    }
    
    public void showChart() {
    	this.overPane.setVisible(false);
    }

    
    
    
    
    
    
    
}
