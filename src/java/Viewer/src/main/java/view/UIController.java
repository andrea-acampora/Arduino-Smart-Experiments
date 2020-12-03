package view;

import controllers.Controller;
import controllers.Loop;

import data.ExperimentData;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
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
    
    @FXML
    private Button okButton;

    
    XYChart.Series<Number,Number> speed;
    XYChart.Series<Number,Number> acceleration; 
    
    private Controller controller;
    
    @FXML
    public void OKPressed() {
    	this.showChart();
    	this.controller.reportOkPressed();
    	this.clearChart();
    }
    
    public void addSeriesToChart() {
    	this.lineChart.getData().add(speed); 
    	this.lineChart.getData().add(acceleration); 
    }
    
    public void update(final ExperimentData data) {
    	this.setState(data.getState());
    	if (data.getState().equals("IN_EXECUTION")) {
    		this.addData(this.lineChart.getData().get(0).getData().size(), data.getSpeed(), data.getAcceleration(), data.getPosition());
    	} else if (data.getState().equals("TERMINATED")) {
    		this.showButton();
    	}
    }
    
    public void init(final Controller controller) {
    	this.speed = new XYChart.Series<>();
    	this.acceleration = new XYChart.Series<>();
    	this.speed.setName("speed");
    	this.acceleration.setName("acceleration");
    	this.addSeriesToChart();
    	this.overPane.setVisible(false);
    	this.controller = controller;
    }
    
    public void addData(int i, double speedData, double accelerationData, double objectPosition) {
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
    	this.lineChart.getData().get(0).getData().clear();
    	this.lineChart.getData().get(1).getData().clear();
    	this.objectPosition.setProgress(0);
    	this.xAxys.setUpperBound(20);
    }
    
    public void showButton() {
    	this.okButton.setVisible(true);
    	this.overPane.setVisible(true);
    }
    
    public void showChart() {
    	this.overPane.setVisible(false);
    	this.okButton.setVisible(false);
    }
}
