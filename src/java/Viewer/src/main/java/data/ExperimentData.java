package data;

import java.util.LinkedList;
import java.util.List;

public class ExperimentData {
	
	private String state;
	private List<Double> positions;
	private List<Double> speeds;
	private List<Double> accelerations;
	
	public ExperimentData() {
		this.positions = new LinkedList<Double>();
		this.speeds = new LinkedList<Double>();
		this.accelerations = new LinkedList<Double>();
	}
	
	public final void setState(final String state) {
		this.state = state;
	}

	public final void addPosition(final double position) {
		this.positions.add(position);
	}
	
	public final void addSpeed(final double speed) {
		this.speeds.add(speed);
	}
	
	public final void addAcceleration(final double acc) {
		this.accelerations.add(acc);
	}
	
	public final String getState() {
		return this.state;
	}
	
	public final List<Double> getPositions() {
		return this.positions;
	}

	public final List<Double> getSpeeds() {
		return this.speeds;
	}

	public final List<Double> getAccelerations() {
		return this.accelerations;
	}

	
}
