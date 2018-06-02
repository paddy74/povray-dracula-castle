global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 

//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"

// ----------------------------------------
// Camera
// ----------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 75      // front view
                            location  <0.0 , 1.0 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 90   // diagonal view
                            location  <2.0 , 2.5 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90 // right side view
                            location  <3.0 , 1.0 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0.0 , 3.0 ,-0.001>
                            right     x*image_width/image_height
look_at <0.0 , 1.0 , 0.0>}

camera{Camera_0}

// ----------------------------------------
// Enviornment
// ----------------------------------------
// Moon
light_source{ <-1000, 800, 3000> 
              color White
              looks_like{ sphere{ <0,0,0>,300 
                                  texture{ pigment{ color White }
                                           normal { bumps 0.5
                                                    scale 50    }
                                           finish { ambient 0.8   
                                                    diffuse 0.2
                                                    phong 1     }
                                                  
                                         } // end of texture
                                } // end of sphere
                        } //end of looks_like
            } //end of light_source

// Clouds 
plane{<0,1,0>,1 hollow  
       texture{pigment{ bozo turbulence 0.76
                        color_map { [0.5 rgbf<1.0,1.0,1.0,1.0> ]
                                    [0.6 rgb <1.0,1.0,1.0>     ]
                                    [1.0 rgb <0.5,0.5,0.5>     ]}
                       }
               finish { ambient 0.25 diffuse 0} 
              }      
       scale 500}

// Fog
fog{ fog_type   2
     distance   50
     color      White
     fog_offset 0.1
     fog_alt    2.0
     turbulence 0.8
   }

// Ground
plane { <0,1,0>, 0 
        texture { pigment{ color rgb<0.35,0.65,0.0>*0.72}
                  normal { bumps 0.75 scale 0.015  }
                  finish { phong 0.1 }
                }
}

// ----------------------------------------
// Textures
// ----------------------------------------
#declare Brick_Scale     = < 0.064,0.065,0.140>; 
#declare Brick_Translate = < 0.00,-0.20,  0.30>*3;
#declare Brick_Intensity = 0.35; 

// Wall Textures
#declare Wall_Texture_1 = // sand stone
         texture { pigment{ color rgb< 0.90, 0.78, 0.60>}
                   normal { pigment_pattern{ brick 
                                             color rgb 0.2, 
                                             color rgb 0.8 
                                             scale Brick_Scale 
                                             translate Brick_Translate
                                             rotate<0,0,0>} Brick_Intensity}
                   finish { diffuse 0.9 phong 0.1}
                 } // end of texture 
#declare Wall_Texture_2 = // sand stone
         texture { pigment{ color rgb< 0.90, 0.78, 0.60>*0.95}
                            // color rgb< 0.4,1,0.0>} // test_color
                   normal { pigment_pattern{ brick 
                                             color rgb 0.2, 
                                             color rgb 0.8 
                                             scale Brick_Scale
                                             translate Brick_Translate
                                             rotate<0,90,0>} Brick_Intensity}
                   finish { diffuse 0.9 phong 0.1}
                 } // end of texture


#declare Tower_Texture_1 = // sandstone
         texture { pigment{ color rgb< 0.90, 0.78, 0.60>*1.2}
                   normal { pigment_pattern{ brick 
                                             
                                             color rgb 0.2, 
                                             color rgb 0.8    //mortar 0.10
                                             scale Brick_Scale 
                                             translate Brick_Translate
                                             rotate<0,0,0>} Brick_Intensity}
                   finish { phong 0.1}
                 } // end of texture 
#declare Tower_Texture_2 = // sandstone
         texture { pigment{ color rgb< 0.90, 0.78, 0.60>*0.95*1.2}
                            // color rgb< 0.4,1,0.0>} // test_color
                   normal { pigment_pattern{ brick 
                                             color rgb 0.2, 
                                             color rgb 0.8 
                                             scale Brick_Scale
                                             translate Brick_Translate
                                             rotate<0,0,0>} Brick_Intensity}
                   finish { phong 0.1}
                 } // end of texture 

// ----------------------------------------
// Castle Right
// ----------------------------------------
#include "Battlements_0.inc"

object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         4.00, // Wall__H, // wall heigth in y 
                         1.20, // Wall__D, // wall deepth in z 
                         1.50, // Balustrade_H, // balustrade high
                         0.30, // Battlement__Wall_D, // battlement wall deepth 
                         0.80, // Battlement__H,    // battlements height in y
                         0.25, // Battlement__R,  // half battlements width in x or z 
                         1, // Tween__Distance, //  >2*Battlement__R;  tween distance 
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,.5,.5>*1
        rotate<0,180,0> 
        translate<10.00,0.00, 15.00>}

object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         4.00, // Wall__H, // wall heigth in y 
                         1.20, // Wall__D, // wall deepth in z 
                         1.50, // Balustrade_H, // balustrade high
                         0.30, // Battlement__Wall_D, // battlement wall deepth 
                         0.80, // Battlement__H,    // battlements height in y
                         0.25, // Battlement__R,  // half battlements width in x or z 
                         1, // Tween__Distance, //  >2*Battlement__R;  tween distance 
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,.5,.5>*1
        rotate<0,0,0> 
        translate<9.50,0.00, 12.00>}


#include "Tower_Round_0"

object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <.5,1,.5>*1
        rotate<0, 0,0> 
        translate<12.00,0.00, 13.00>}

object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <.5,.5,.5>*1
        rotate<0, 0,0> 
        translate<10.00,0.00, 13.00>}

object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         4.00, // Wall__H, // wall heigth in y 
                         1.20, // Wall__D, // wall deepth in z 
                         1.50, // Balustrade_H, // balustrade high
                         0.30, // Battlement__Wall_D, // battlement wall deepth 
                         0.80, // Battlement__H,    // battlements height in y
                         0.25, // Battlement__R,  // half battlements width in x or z 
                         1, // Tween__Distance, //  >2*Battlement__R;  tween distance 
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <4,.5,.5>*1
        rotate<0,90,0> 
        translate<6.50, 0.00, 24.00>}


// ----------------------------------------
// Castle Center
// ----------------------------------------
#include "Tower_Squared_0.inc"

object{ Tower_Squared_0( 2.00, // Tower_R, // half tower width in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.25, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Merlon_H,       // battlements height in y
                         0.22, // Merlon_R,   // half battlements width in x or z 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <3,1,1>*1
        rotate<0,0,0> 
        translate<0.00,0.00, 30.00>}

object{ Tower_Squared_0( 2.00, // Tower_R, // half tower width in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.25, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Merlon_H,       // battlements height in y
                         0.22, // Merlon_R,   // half battlements width in x or z 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <10,.5,.5>*1
        rotate<0,0,0> 
        translate<0.00,0.00, 30.00>}

// Gate


// ----------------------------------------
// Castle Left
// ----------------------------------------
object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         4.00, // Wall__H, // wall heigth in y 
                         1.20, // Wall__D, // wall deepth in z 
                         1.50, // Balustrade_H, // balustrade high
                         0.30, // Battlement__Wall_D, // battlement wall deepth 
                         0.80, // Battlement__H,    // battlements height in y
                         0.25, // Battlement__R,  // half battlements width in x or z 
                         1, // Tween__Distance, //  >2*Battlement__R;  tween distance 
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,.5,.5>*1
        rotate<0,180,0> 
        translate<-10.00, 0.00, 15.00>}

object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         4.00, // Wall__H, // wall heigth in y 
                         1.20, // Wall__D, // wall deepth in z 
                         1.50, // Balustrade_H, // balustrade high
                         0.30, // Battlement__Wall_D, // battlement wall deepth 
                         0.80, // Battlement__H,    // battlements height in y
                         0.25, // Battlement__R,  // half battlements width in x or z 
                         1, // Tween__Distance, //  >2*Battlement__R;  tween distance 
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <1,.5,.5>*1
        rotate<0,0,0> 
        translate<-9.50, 0.00, 12.00>}

object{ Battlements_0(   3.00, // Wall__W, // half wall width in x                                
                         4.00, // Wall__H, // wall heigth in y 
                         1.20, // Wall__D, // wall deepth in z 
                         1.50, // Balustrade_H, // balustrade high
                         0.30, // Battlement__Wall_D, // battlement wall deepth 
                         0.80, // Battlement__H,    // battlements height in y
                         0.25, // Battlement__R,  // half battlements width in x or z 
                         1, // Tween__Distance, //  >2*Battlement__R;  tween distance 
                         Wall_Texture_1, // outside texture
                         Wall_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <4,.5,.5>*1
        rotate<0,-90,0> 
        translate<-6.50, 0.00, 24.00>}

object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <.5,1,.5>*1
        rotate<0, 0,0> 
        translate<-12.00,0.00, 13.00>}

object{ Tower_Round_0(   2.50, // Tower_R, // tower radius in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.35, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Battlements_H,           // battlements height in y
                         15.5 // Battlements_Angle,   // battlements angle in xz around y 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <.5,.5,.5>*1
        rotate<0, 0,0> 
        translate<-10.00,0.00, 13.00>}


// ----------------------------------------
// Moat
// ----------------------------------------
#declare  Pool_Border_Texture = 
       texture{ pigment{ color rgb <1.00, 1.00, 1.00>*1.1} 
                normal { agate 0.5 scale 0.15 rotate<0,0,0> }
                 finish { phong 1 } 
                rotate<0,0,0> scale 0.25 translate<0,0,0>
              } // end of texture 

#declare Pool_Water_Texture =
         texture { Polished_Chrome
                   normal { bumps 0.15 scale 0.25} 
                   finish { reflection 0.65 } 
                 } // end of texture 

#include "Pool_00.inc" 

object{ Pool_00( 4.00, // width in x
                 6.00, // width in z 
                 0.50, // >0,  Pool_Border_Width,  
                 0.15, // Pool_Border_Height, // >0
                 -1.50, // Pool_Depth_Y, // negativ value!  
                 Pool_Border_Texture, // 
                 Pool_Water_Texture //
               ) 
    scale <10,1,.5> 
    rotate<0,0,0> 
    translate<-7,0,.75>  
 }


#include "Street_10.inc" 

object{ Street_10( 4,     // Street_Widthm, // 
                   1000 , // Street_Length, //
                   0.10,  // Stripes_Width, // 
                   1.00,  // Stripes_Length // = 0 => continuous line!!!                                 
                 ) //------------------------------------------------------------------//
        scale <1,1,30>*1
        rotate<0,90,0> 
        translate<-10.00,0.00, 3.00>}


// ----------------------------------------
// Moat Wall
// ----------------------------------------
object{ Tower_Squared_0( 2.00, // Tower_R, // half tower width in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.25, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Merlon_H,       // battlements height in y
                         0.22, // Merlon_R,   // half battlements width in x or z 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <2,.1,.1>*1
        rotate<0,0,0> 
        translate<5.00,0.00, 4>}

object{ Tower_Squared_0( 2.00, // Tower_R, // half tower width in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.25, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Merlon_H,       // battlements height in y
                         0.22, // Merlon_R,   // half battlements width in x or z 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <2,.1,.1>*1
        rotate<0,0,0> 
        translate<-5.00,0.00, 4>}


// ----------------------------------------
// Bridge
// ----------------------------------------
object{ Tower_Squared_0( 2.00, // Tower_R, // half tower width in x and z                                
                         8.00, // Tower_H, // tower heigth in y 
                         1.50, // Tower_Balustrade_H, // tower balustrade high
                         0.25, // Tower_Wall_D,       // tower wall deepth 
                         0.66, // Merlon_H,       // battlements height in y
                         0.22, // Merlon_R,   // half battlements width in x or z 
                         Tower_Texture_1, // outside texture
                         Tower_Texture_2  // battlements tween texture
                       ) //------------------------------------------------------------// 
        scale <.5,.025,1>*1
        rotate<0,0,0> 
        translate<0.00,0.00, 2.50>}


// ----------------------------------------
// Dragon
// ----------------------------------------
#local dragon_detail = 0;                     // skeleton or detail
#declare dragon_rot = <0,130,0>;        // dragon base rotation
#declare dragon_trs = <5,3,20>; // dragon base location

#include "dragon.inc"
