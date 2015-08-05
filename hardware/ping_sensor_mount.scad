sensor_width = 45.35;
sensor_height = 20.38;
sensor_depth = 15.43;
barrel_edge = 1.8;
barrel_between = 10.21;
barrel_diameter = 15.94;
barrel_height = 12.23;
xtal_height = 3.55;
xtal_width = 10.80;
conn_width = 10.52;
conn_pin_length = 5.41;

// sensor bounding box (minus connector)
//cube([sensor_width, sensor_height, sensor_depth]);

difference(){
	// mounting plate
	cube([sensor_width + 2, sensor_height + 2, 2]);

	// barrel holes
	translate([barrel_edge+(barrel_diameter/2)+1,barrel_edge+(barrel_diameter/2)+1,-1]){
		#cylinder(r=barrel_diameter/2+.1,h=barrel_height,$fn=50);
	}
	translate([barrel_edge + barrel_between + barrel_diameter + (barrel_diameter/2)+1,barrel_edge+(barrel_diameter/2)+1,-1]){
		#cylinder(r=barrel_diameter/2+.1,h=barrel_height,$fn=50);
	}
}