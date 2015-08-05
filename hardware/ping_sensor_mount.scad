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
cube([sensor_width, sensor_height, sensor_depth]);

// barrels
cylinder(r=barrel_diameter/2,h=barrel_height);