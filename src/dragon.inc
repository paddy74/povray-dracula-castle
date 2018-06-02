// materials
#local spike_t =
texture { pigment{rgb 0} finish {diffuse .05 specular .4 roughness .1 ambient 0}}
#local wing_t = 
texture { 
  pigment {granite color_map{[0 rgb 0][1 rgb <.8,0,0>]} scale .2}
  normal {granite .3 scale .2}
  finish {diffuse .4 specular .03 roughness .02 ambient 0}
}
#local dragon_skin_t = 
texture { 
  pigment {crackle color_map{[0 rgb <.2,0,0>][1 rgb <.8,0,0>]} scale .1}
  normal{crackle 1 scale .03}
  finish {diffuse .4 specular .03 roughness .02 ambient 0}
}

// Control points for body, adjust if needed
#local body = array[9]
{
  <0,0,1.05>,
  <0,.75,.8>,
  <0,1,.5>,
  <0,1,0>,
  <0,.5,-.5>,
  <0,-.3,-.6>,
  <0,-1,-.3>,
  <0,-1.5,.2>,
  <0,-1.5,.6>
}

// Control poits for RIGHT wing
#local l_wing = array[11]
{
        body[3]
        body[3]+<.5,.5,.1>,
        body[3]+<1,.6,.5>,

        body[3]+<2,.2,1>,
        body[3]+<3,-.25,.8>,

        body[3]+<2.2,.2,.25>,
        body[3]+<2.95,-.3,-.1>,

        body[3]+<1.8,.25,-.1>,
        body[3]+<2.1,-.3,-.6>,

        body[3]+<1,.3,-.5>,
        body[3]+<1,-.4,-.8>,
}

// Control poits for LEFT wing
#local r_wing = array[11]
{
        body[3],
        body[3]+<-.5,.5,.1>,
        body[3]+<-1,.6,.5>,

        body[3]+<-2,.2,1>,
        body[3]+<-3,-.25,.8>,

        body[3]+<-2.2,.2,.25>,
        body[3]+<-2.95,-.3,-.1>,

        body[3]+<-1.8,.25,-.1>,
        body[3]+<-2.1,-.3,-.6>,

        body[3]+<-1,.3,-.5>,
        body[3]+<-1,-.4,-.8>,
}

// control points for front legs
// both two are in same array to make things complicated
#local f_legs = array[5]
{
        body[3],
        body[3]+<.25,-.05,.15>,
        body[3]+<.2,-.1,.5>,
        body[3]+<-.15,-.3,0>,
        body[3]+<-.25,-.5,.25>
}

// control points for back legs
// both two are in same array to make things complicated
#local b_legs = array[5]
{
        body[4],
        body[4]+<.15,-.2,.2>,
        body[4]+<.25,-.5,.5>,
        body[4]+<-.15,-.15,.4>,
        body[4]+<-.25,-.35,.6>
}


union {
//////////////////
#if(dragon_detail)
/*
#local spike =
sphere_sweep {
  cubic_spline 
  4  
    <0,-.1,0> .05
    <0,0,0> .05
    <0,.5,-.2> .0001
    <0,.5,-.3> .0001
    texture{spike_t}
}

// spikes at back of the dragon completely automatic
object{spike rotate x*30 scale .6 translate (body[1]+body[2])/2}
object{spike rotate x*20 scale .65 translate body[2]}
object{spike rotate x*10 scale .75 translate (body[2]+body[3])/2}
object{spike rotate x*0 scale .85 translate body[3]}
object{spike rotate x*-10 scale .85 translate body[4]}
object{spike rotate x*-30 scale .85 translate body[5]}
object{spike rotate x*-60 scale .75 translate (body[6]+body[5])/2+<0,0,-.1>}
object{spike rotate x*-90 scale .75 translate body[6] translate <0,.6,-.5>}
object{spike rotate x*-90 scale .75 translate body[6] translate <0,.3,-.3>}
object{spike rotate x*-110 scale .75 translate body[6]}
object{spike rotate x*-120 scale .5 translate (body[6]+body[7])/2 translate <0,0,-.1>}

// head, upper part
blob {
    threshold .1
    cylinder {<0,.075,0><0,.075,.4> .08 1 scale <1,.75,1>}
    cylinder {<0,.15,0><0,.15,.2> .08 1 scale <.9,.7,1>}
    cylinder {
        <0,.15,.1><0,.15,.15> .07, -.6 scale <1,.6,1>
        pigment{rgb y}finish{ambient .01}
    }
    rotate x*30 // adjust this to open and close the mouth
    translate <0,.08,-.1>
    translate body[1]
}
// head, lower part
blob {
    threshold .1
    cylinder {<0,.075,0><0,.075,.3> .08 1 scale <1,.5,1>}
    rotate x*75 // adjust this to open and close the mouth
    translate <0,.08,-.1>
    translate body[1]
}
// horns
object{spike rotate x*-10 rotate z*20  scale 1 translate body[1] +<.0125,.1,0>}
object{spike rotate x*-10 rotate z*-20 scale 1 translate body[1] +<-.0125,.1,0>}

//body
sphere_sweep {
  cubic_spline 
  9
  body[0] .08
  body[1] .08
  body[2] .08
  body[3] .16
  body[4] .15
  body[5] .1
  body[6] .05
  body[7] .01
  body[8] .01
    texture { dragon_skin_t }
    #local dsk2 = <.7,.6,.3>;
    texture { 
        pigment {
            spherical
            color_map {
                [0 rgbt dsk2+<0,0,0,1>]
                [.3 rgbt dsk2+<0,0,0,1>]
                [1 rgbt dsk2+<0,0,0,.3>]
            }
            scale <1,1.5,1>
            translate <0,-.125,.175>
        }
    normal{crackle 1 scale .03}
      finish {diffuse .4 specular .03 roughness .02 ambient 0}
    }
}

// right wing
sphere_sweep {
  linear_spline 
  5
  l_wing[0] .1
  l_wing[1] .075

  l_wing[2] .05
  l_wing[3] .03
  l_wing[4] .02
}
object{spike scale .4 rotate x*260 rotate y*-85 translate l_wing[4]}

sphere_sweep {
  linear_spline
  3
  l_wing[2] .05
  l_wing[5] .03
  l_wing[6] .02
}
object{spike scale .4 rotate x*260 rotate y*-50 translate l_wing[6]}

sphere_sweep {
  linear_spline
  3
  l_wing[2] .05
  l_wing[7] .03
  l_wing[8] .02
}
object{spike scale .4 rotate x*245 translate l_wing[8]}

sphere_sweep {
  linear_spline
  3
  l_wing[2] .05
  l_wing[9] .03
  l_wing[10] .02
}
object{spike scale .4 rotate x*200 translate l_wing[10]}

// left wing
sphere_sweep {
  linear_spline 
  5
  r_wing[0] .1
  r_wing[1] .075

  r_wing[2] .05
  r_wing[3] .03
  r_wing[4] .02
}
object{spike scale .4 rotate x*260 rotate y*85 translate r_wing[4]}


sphere_sweep {
  linear_spline
  3
  r_wing[2] .05
  r_wing[5] .03
  r_wing[6] .02
}
object{spike scale .4 rotate x*260 rotate y*50 translate r_wing[6]}

sphere_sweep {
  linear_spline
  3
  r_wing[2] .05
  r_wing[7] .03
  r_wing[8] .02
}
object{spike scale .4 rotate x*245 translate r_wing[8]}

sphere_sweep {
  linear_spline
  3
  r_wing[2] .05
  r_wing[9] .03
  r_wing[10] .02
}
object{spike scale .4 rotate x*200 translate r_wing[10]}


%w=<0,0,0,1>;
%w2=<0,0,0,50>;
%acc = .001;
union
{
  bezier_patch {
    3 3
    accuracy acc rational
    l_wing[2]+w l_wing[3]+w2 l_wing[4]+w
    l_wing[2]+w (l_wing[3]+l_wing[5])/2+<0,.2,0>+w (l_wing[4]+l_wing[6])/2+<0,.2,0>+w
    l_wing[2]+w l_wing[5]+w2 l_wing[6]+w
  }
  bezier_patch {
    3 3
    accuracy acc rational
    l_wing[2]+w l_wing[5]+w2 l_wing[6]+w
    l_wing[2]+w (l_wing[5]+l_wing[5])/2+<0,.2,0>+w (l_wing[6]+l_wing[8])/2+<0,.2,0>+w
    l_wing[2]+w l_wing[7]+w2 l_wing[8]+w
  }
  bezier_patch {
    3 3
    accuracy acc rational
    l_wing[2]+w l_wing[7]+w2 l_wing[8]+w
    l_wing[2]+w (l_wing[7]+l_wing[9])/2+<0,.2,0>+w (l_wing[8]+l_wing[10])/2+<0,.2,0>+w
    l_wing[2]+w l_wing[9]+w2 l_wing[10]+w
  }
  bezier_patch {
    3 3
    accuracy acc rational
    l_wing[2]+w l_wing[1]+w2 l_wing[0]+w
    l_wing[9]+w2 (l_wing[9]+(l_wing[0]+body[4])/2)/2+<0,.4,0>+w  (l_wing[0]+body[4])/2+w2
    l_wing[10]+w (body[4]+l_wing[10])/2+<0,.2,0>+w body[4]+w
  }

  bezier_patch {
    3 3
    accuracy acc rational
    r_wing[2]+w r_wing[3]+w2 r_wing[4]+w
    r_wing[2]+w (r_wing[3]+r_wing[5])/2+<0,.2,0>+w (r_wing[4]+r_wing[6])/2+<0,.2,0>+w
    r_wing[2]+w r_wing[5]+w2 r_wing[6]+w
  }
  bezier_patch {
    3 3
    accuracy acc rational
    r_wing[2]+w r_wing[5]+w2 r_wing[6]+w
    r_wing[2]+w (r_wing[5]+r_wing[5])/2+<0,.2,0>+w (r_wing[6]+r_wing[8])/2+<0,.2,0>+w
    r_wing[2]+w r_wing[7]+w2 r_wing[8]+w
  }
  bezier_patch {
    3 3
    accuracy acc rational
    r_wing[2]+w r_wing[7]+w2 r_wing[8]+w
    r_wing[2]+w (r_wing[7]+r_wing[9])/2+<0,.2,0>+w (r_wing[8]+r_wing[10])/2+<0,.2,0>+w
    r_wing[2]+w r_wing[9]+w2 r_wing[10]+w
  }
  bezier_patch
  {
    3 3
    accuracy acc rational
    r_wing[2]+w r_wing[1]+w2 r_wing[0]+w
    r_wing[9]+w2 (r_wing[9]+(r_wing[0]+body[4])/2)/2+<0,.4,0>+w  (r_wing[0]+body[4])/2+w2
    r_wing[10]+w (body[4]+l_wing[10])/2+<0,.2,0>+w body[4]+w
  }

  texture{wing_t}
}

// legs
sphere_sweep {
  linear_spline
  3
  f_legs[0] .1
  f_legs[1] .075
  f_legs[2] .05
}
sphere_sweep {
  linear_spline
  3
  f_legs[0] .1
  f_legs[3] .075
  f_legs[4] .05
}
sphere_sweep {
  linear_spline
  3
  b_legs[0] .15
  b_legs[1] .075
  b_legs[2] .05
}
sphere_sweep {
  linear_spline
  3
  b_legs[0] .15
  b_legs[3] .075
  b_legs[4] .05
}

// back feet
sphere_sweep { linear_spline 2 b_legs[2] .05 b_legs[2]+<0,0,-.1> .03 }
sphere_sweep { linear_spline 2 b_legs[4] .05 b_legs[4]+<0,-.09,0> .03 }
sphere_sweep { linear_spline 2 b_legs[2] .05 b_legs[2]+<.05,0,.08> .03 }
sphere_sweep { linear_spline 2 b_legs[2] .05 b_legs[2]+< 0,0,.1> .03 }
sphere_sweep { linear_spline 2 b_legs[2] .05 b_legs[2]+<-.05,0,.08> .03 }
sphere_sweep { linear_spline 2 b_legs[4] .05 b_legs[4]+<0,.075,.06> .03 }
sphere_sweep { linear_spline 2 b_legs[4] .05 b_legs[4]+<0,.09,.12> .03 }
sphere_sweep { linear_spline 2 b_legs[4] .05 b_legs[4]+<-.05,.075,.06> .03 }

// talons
union {
sphere_sweep { linear_spline 2 b_legs[2]+<0,0,-.1> .03 b_legs[2]+<0,-.1,-.1> .001}
sphere_sweep { linear_spline 2 b_legs[4]+<0,-.09,0> .03 b_legs[4]+<0,-.15,.1> .001}
sphere_sweep { linear_spline 2 b_legs[2]+<.05,0,.08> .03 b_legs[2]+<.1,-.1,.16> .001}
sphere_sweep { linear_spline 2 b_legs[2]+<0,0,.1> .03 b_legs[2]+<0,-.1,.16> .001}
sphere_sweep { linear_spline 2 b_legs[2]+<-.05,0,.08> .03 b_legs[2]+<-.1,-.1,.16> .001}
sphere_sweep { linear_spline 2 b_legs[4]+<.05,.075,.06> .03 b_legs[4]+<.05,.1,.16> .001}
sphere_sweep { linear_spline 2 b_legs[4]+<0,.09,.12> .03 b_legs[4]+<0,.12,.22> .001}
sphere_sweep { linear_spline 2 b_legs[4]+<-.05,.075,.06> .03 b_legs[4]+<-.05,.1,.16> .001}

sphere_sweep { linear_spline 2 f_legs[2]+<0,-.09,0> .03 f_legs[2]+<0,-.12,.15> .001}
sphere_sweep { linear_spline 2 f_legs[4]+<0,-.09,0> .03 f_legs[4]+<0,-.15,.1> .001}
sphere_sweep { linear_spline 2 f_legs[2]+<.05,.075,.06> .03 f_legs[2]+<.05,.105,.21> .001}
sphere_sweep { linear_spline 2 f_legs[2]+<0,.09,.06> .03 f_legs[2]+<0,.11,.21> .001}
sphere_sweep { linear_spline 2 f_legs[2]+<-.05,.075,.06> .03 f_legs[2]+<-.05,.1,.16> .001}
sphere_sweep { linear_spline 2 f_legs[4]+<.05,.075,.06> .03 f_legs[4]+<.05,.1,.16> .001}
sphere_sweep { linear_spline 2 f_legs[4]+<0,.09,.06> .03 f_legs[4]+<0,.12,.16> .001}
sphere_sweep { linear_spline 2 f_legs[4]+<-.05,.075,.06> .03 f_legs[4]+<-.05,.1,.16> .001}

texture {spike_t}
}
// fron feet
sphere_sweep { linear_spline 2 f_legs[2]+<0,-.09,0> .03 f_legs[2] .05}
sphere_sweep { linear_spline 2 f_legs[4]+<0,-.09,0> .03 f_legs[4] .05}
sphere_sweep { linear_spline 2 f_legs[2]+<.05,.075,.06> .03 f_legs[2] .05}
sphere_sweep { linear_spline 2 f_legs[2]+<0,.09,.06> .03 f_legs[2] .05}
sphere_sweep { linear_spline 2 f_legs[2]+<-.05,.075,.06> .03 f_legs[2] .05}
sphere_sweep { linear_spline 2 f_legs[4]+<.05,.075,.06> .03 f_legs[4] .05}
sphere_sweep { linear_spline 2 f_legs[4]+<0,.09,.06> .03 f_legs[4] .05}
sphere_sweep { linear_spline 2 f_legs[4]+<-.05,.075,.06> .03 f_legs[4] .05}
*/
//////////////////
#else

// skeleton
union {
  cylinder {body[1] body[2] .1}
  cylinder {body[2] body[3] .1}
  cylinder {body[3] body[4] .1}
  cylinder {body[4] body[5] .1}
  cylinder {body[5] body[6] .1}
  cylinder {body[6] body[7] .1}
    texture { dragon_skin_t }
    #local dsk2 = <.7,.6,.3>;
    texture { 
        pigment {
            spherical
            color_map {
                [0 rgbt dsk2+<0,0,0,1>]
                [.3 rgbt dsk2+<0,0,0,1>]
                [.35 rgb dsk2]
                [1 rgb dsk2]
            }
            scale <1,1.5,1>
            translate <0,-.125,.175>
        }
    }
}
  cylinder {l_wing[0] l_wing[1] .1}
  cylinder {l_wing[1] l_wing[2] .1}

  cylinder {l_wing[2] l_wing[3] .1}
  cylinder {l_wing[3] l_wing[4] .1}

  cylinder {l_wing[2] l_wing[5] .1}
  cylinder {l_wing[5] l_wing[6] .1}

  cylinder {l_wing[2] l_wing[7] .1}
  cylinder {l_wing[7] l_wing[8] .1}

  cylinder {l_wing[2] l_wing[9] .1}
  cylinder {l_wing[9] l_wing[10] .1}

  cylinder {r_wing[0] r_wing[1] .1}
  cylinder {r_wing[1] r_wing[2] .1}

  cylinder {r_wing[2] r_wing[3] .1}
  cylinder {r_wing[3] r_wing[4] .1}

  cylinder {r_wing[2] r_wing[5] .1}
  cylinder {r_wing[5] r_wing[6] .1}

  cylinder {r_wing[2] r_wing[7] .1}
  cylinder {r_wing[7] r_wing[8] .1}

  cylinder {r_wing[2] r_wing[9] .1}
  cylinder {r_wing[9] r_wing[10] .1}

  cylinder {f_legs[0] f_legs[1] .1}
  cylinder {f_legs[1] f_legs[2] .1}

  cylinder {f_legs[0] f_legs[3] .1}
  cylinder {f_legs[3] f_legs[4] .1}

  cylinder {b_legs[0] b_legs[1] .1}
  cylinder {b_legs[1] b_legs[2] .1}

  cylinder {b_legs[0] b_legs[3] .1}
  cylinder {b_legs[3] b_legs[4] .1}

//////////////////
#end        

// fire
  sphere
  {
    0 1
    pigment {rgbt 1}
    interior { 
      media { 
                samples 4,6
          emission 4
        density {
                    spherical
                    color_map{[0 rgb 0][.2 rgb 0][.5 rgb <.6,.2,0>][1 rgb <1,1,0>]}
                    turbulence 1.2
                }
      } 
    }
        rotate z*-45
    translate <0,0,1>
    hollow
    scale <.2,.2,1>
        rotate x*50
    translate body[1]
  }
  light_source
  {
      <0,0,1> rgb <.45,.3,.05> 
      area_light <0,1,0> <0,0,1.5> 1 5
      fade_distance 2 fade_power 4
      rotate x*50
  translate body[1]
  }
  texture { dragon_skin_t }
  rotate dragon_rot
  translate dragon_trs

}
