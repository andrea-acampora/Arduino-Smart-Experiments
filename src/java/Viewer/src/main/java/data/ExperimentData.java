package data;


import java.util.LinkedList;
import java.util.List;

public class ExperimentData {
	
	private String state;
	private double position;
	private double speed;
	private double acceleration;

	
	public final void setState(final String state) {
		this.state = state;
	}

	public final void addPosition(final double position) {
		this.position = position;
	}
	
	public final void addSpeed(final double speed) {
		this.speed = speed;
	}
	
	public final void addAcceleration(final double acc) {
		this.acceleration = acc;
	}
	
	public final String getState() {
		return this.state;
	}
	
	public final double  getPosition() {
		return this.position;
	}

	public final double getSpeed() {
		return this.speed;
	}

	public final double getAcceleration() {
		return this.acceleration;
	}

}
