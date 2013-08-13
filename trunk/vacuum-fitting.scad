hose_inner = 40;
hose_length = 40;
wall_thickness = 2;

clamp_inner = 13;
clamp_width = 50;
cone_height = 50;

plate_width = 40;
plate_length = 80;

hole_margin = 6;

translate([0,0,cone_height])
  difference() {
    cylinder(r=hose_inner/2+wall_thickness, h=hose_length);
    translate([0,0,-0.1]) cylinder(r=hose_inner/2, h=hose_length+0.2);
  }

difference() {
  union() {
    hull() {
      translate([0,0,cone_height])cylinder(r=hose_inner/2+wall_thickness, h=2);
      translate([-clamp_width/2, 0, 0]) cylinder(r=clamp_inner/2+wall_thickness, h=2);
      translate([clamp_width/2, 0, 0]) cylinder(r=clamp_inner/2+wall_thickness, h=2);
    }
    translate([0,0,2]) cube([plate_length,plate_width,4], center=true);
  }
  hull() {
    translate([0,0,cone_height+0.1]) cylinder(r=hose_inner/2, h=2);
    translate([-clamp_width/2, 0, -0.1]) cylinder(r=clamp_inner/2, h=2);
    translate([clamp_width/2, 0, -0.1]) cylinder(r=clamp_inner/2, h=2);
  }
  translate([plate_length/2-hole_margin,plate_width/2-hole_margin,0]) cylinder(r=1.5, h=10, center=true, $fn=8);
  translate([-(plate_length/2-hole_margin),plate_width/2-hole_margin,0]) cylinder(r=1.5, h=10, center=true, $fn=8);
  translate([plate_length/2-hole_margin,-(plate_width/2-hole_margin),0]) cylinder(r=1.5, h=10, center=true, $fn=8);
  translate([-(plate_length/2-hole_margin),-(plate_width/2-hole_margin),0]) cylinder(r=1.5, h=10, center=true, $fn=8);
}

