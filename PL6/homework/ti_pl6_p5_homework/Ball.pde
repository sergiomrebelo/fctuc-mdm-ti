class ball{
    PVector pos;
    PVector dir;
    
    int rad;
    
    ball(int _x, int _y, int _rad) {
         pos=new PVector(0,0);
         dir=new PVector(0,0);
         pos.x=_x;
         pos.y=_y;
         rad=_rad;
         dir.x=0;
         dir.y=-1;
    }
    
    /* Ajustar ângulo em função da repetição das teclas quando premidas.
    Em MacOS funcionam bem valores mais altos, noutros sistemas deverão ensaiar-se
    valores mais baixos */
    
    void steer(char cmd){
      if (cmd=='L') dir.rotate(radians(-3));
      else if (cmd=='R') dir.rotate(radians(3));;
    }
    
    void move(){
      pos.add(dir);
    }
    
    void collide(){
      PVector plim=new PVector();
      plim=PVector.add(pos,dir);
      // handle colision with edges
      if ((plim.x>width-rad) || (plim.x<rad)) dir.rotate(2*(HALF_PI-dir.heading()));
      if ((plim.y>width-rad) || (plim.y<rad)) dir.rotate(-2*(dir.heading()));

    }
    
    void show(){
        ellipse(pos.x,pos.y,rad*2,rad*2);
        line(pos.x,pos.y,pos.x+10*cos(dir.heading()),pos.y+10*sin(dir.heading()));
    }
    
}
