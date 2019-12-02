#include "rsdl.hpp"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Geometry Invaders"
#define BACK_SPACE 8
#define RETURN 13
#define USER_INPUT_SIZE_MAX 10
#define UP_ARROW 119
#define DOWN_ARROW 115
#define TO_LASER 's'
#define TO_NORMAL 'n'
#define BOMB 'b'
#define QUIT 'q'

#define TICK_DURATION 1
#define CURSOR_AGE 50

#define EASY 0
#define NORMAL 1
#define HARD 2

#define EASY_PROBABILITY 1
#define NORMAL_PROBABILITY 3
#define HARD_PROBABILITY 9
#define EASY_MAX_DIAMOND 10
#define NORMAL_MAX_DIAMOND 20
#define HARD_MAX_DIAMOND 40
#define EASY_PARTICLE_POINT 5
#define NORMAL_PARTICLE_POINT 10
#define HARD_PARTICLE_POINT 15
#define EASY_DIAMOND_POINT 20
#define NORMAL_DIAMOND_POINT 40
#define HARD_DIAMOND_POINT 80
#define EASY_THRESHOLD 1250
#define NORMAL_THRESHOLD 750
#define HARD_THRESHOLD 500

#define IMG_SQUARE "./square.png"
#define IMG_BACKGROUND "./background.jpg"
#define FONT_FREESANS "./FreeSans.ttf"
#define IMG_DRONE "./drone.png"
#define IMG_DIAMOND "./diamond.png"
#define IMG_SHOOT "./shoot.png"
#define IMG_PARTICLE "./particle.png"
#define IMG_LASER_DRONE "./laser_drone.png"
#define IMG_LASER "./laser.png"
#define IMG_BOOM "./booom.png"
#define IMG_BOOM_DIAMOND "./boom_diamond.png"

#define PI 3.14159265
#define WIDTH_PART 8
#define NOT_COLLIDING -1
#define NOT_FOUND -1
#define GO_BACK -1
#define EXIT -2

struct Drone
{
  double x,y;
  double v_x,v_y;
  double x_h,y_h;
  double width,height;
  double angle;
  double ati;
};

struct Diamond
{
  double x,y;
  double v_x,v_y;
  double width,height;
  double angle;
};

struct Killed_Diamond 
{
  double x,y;
  double v_x,v_y;
  double width,height;
  double angle;
  int ttl;
};

struct Shoot
{
  double x,y;
  double v_x,v_y;
  double width,height;
  double angle;
};

struct Laser
{
  double x,y;
  double v_x,v_y;
  double width,height;
  double angle;
};

struct Particle
{
  double x,y;
  double v_x,v_y;
  double width,height;
  double angle;
  double time;
};

struct Top_people
{
  string name;
  int score;
};


Killed_Diamond create_killed_diamond(Diamond diamond){
  Killed_Diamond killed_diamond;
  killed_diamond.x = diamond.x;
  killed_diamond.y = diamond.y;
  killed_diamond.v_x = diamond.v_x;
  killed_diamond.v_y = diamond.v_y;
  killed_diamond.width = diamond.width;
  killed_diamond.height = diamond.height;
  killed_diamond.angle = diamond.angle;
  killed_diamond.ttl = 3;
  return killed_diamond;
}

int run_ready_menu (window& win , int& score , int live , int mode);

Particle create_particle (double x , double y , double v_x , double v_y , double width, double height , double angle , double time ) {
  Particle particle;
  particle.x = x;
  particle.y = y;
  particle.v_x = v_x;
  particle.v_y = v_y;
  particle.width = width;
  particle.height = height;
  particle.angle = angle;
  particle.time = time;
  return particle;
}

Shoot create_shoot(double x , double y , double v_x , double v_y, double width , double height , double angle) {
  Shoot shoot;
  shoot.x = x;
  shoot.y = y;
  shoot.v_x = v_x;
  shoot.v_y = v_y;
  shoot.width = width;
  shoot.height = height;
  shoot.angle = angle;
  return shoot;
}

Laser create_laser(double x , double y , double v_x , double v_y, double width , double height , double angle) {
  Laser laser;
  laser.x = x;
  laser.y = y;
  laser.v_x = v_x;
  laser.v_y = v_y;
  laser.width = width;
  laser.height = height;
  laser.angle = angle;
  return laser;
}

Diamond create_diamond(double x , double y , double v_x , double v_y , double width , double height ) {
  Diamond diamond;
  diamond.x = x;
  diamond.y = y;
  diamond.v_x = v_x;
  diamond.v_y = v_y;
  diamond.width = width;
  diamond.height = height;
  diamond.angle = 0;
  return diamond;
}



Drone create_drone(double x,double y, double v_x, double v_y , double width , double height) {
  Drone drone;
  drone.x = x;
  drone.y = y;
  drone.v_x = v_x;
  drone.v_y = v_y;
  drone.x_h = x + width/2;
  drone.y_h = y + height/2;
  drone.width = width;
  drone.height = height;
  drone.angle = 0;
  drone.ati = 0;
  return drone;
}

string convert_int_to_string (int input) {
  string result;
  stringstream iss;
  iss<<input;
  result = iss.str();
  return result;
}

int convert_string_to_int (string input) {
  int result;
  stringstream(input) >> result;
  return result;
}

Top_people create_top (string name , int score) {
  Top_people new_top;
  new_top.name = name;
  new_top.score = score;
  return new_top;
}

int find_person (vector<Top_people>& tops , Top_people new_top) {
  for (int i = 0; i < tops.size(); ++i)
  {
    if (tops[i].name == new_top.name)
      return i;
  }
  return NOT_FOUND;
}

void add_person (vector<Top_people>& tops , Top_people new_top) {
  
  int position = find_person(tops,new_top);
  if (tops.size() < 5) {
    if(position == NOT_FOUND) {
      tops.push_back(new_top);
      return;
    }
    if(position != NOT_FOUND) {
      if(tops[position].score < new_top.score)
        tops[position].score = new_top.score;
      return;
    }
  }
  if (tops.size() == 5) {
    if(position == NOT_FOUND) {
      if(tops[4].score < new_top.score) {
        tops.pop_back();
        tops.push_back(new_top);
      }
      return;
    }
    if(position != NOT_FOUND) {
      if(tops[position].score < new_top.score) {
        tops[position].score = new_top.score;
      }
      return;
    }
  }
}

bool compare_scores_of_tops (const Top_people &a , const Top_people &b) {
  return a.score > b.score;
}

void process_tops (vector<Top_people>& tops , int score , string name ) {
  Top_people new_top = create_top(name , score);
  add_person(tops , new_top);
  sort(tops.begin() , tops.end() , compare_scores_of_tops);
}

bool collision_of_drone_diamonds(vector<Diamond>& diamonds , Drone& drone) {
  int center_x = drone.x - drone.width/2 * cos(drone.ati*PI/180);
  int center_y = drone.y + drone.height/2 * sin(drone.ati*PI/180);
  for (int i = 0; i < diamonds.size(); ++i)
  {
    
    if (pow(drone.x - diamonds[i].x,2 ) + pow(drone.y - diamonds[i].y , 2) < 25*25)
      return true;
    if (pow(center_x - diamonds[i].x,2) + pow(center_y - diamonds[i].y,2) < 50*50)
      return true;
  }
  return false;
}

void draw_string(window& win, string text , int x , int y) {
  win.show_text(text, 100, 100, WHITE, FONT_FREESANS, 30);
}
void draw_background(window& win) {
  win.draw_bg(IMG_BACKGROUND, 0 ,0);
}

void draw_scoring_menu (window& win , int score) {
  draw_background(win);
  win.fill_rect(20,10,150,40,CYAN);
  win.fill_rect(100, 100, (400 - 1), (50 - 1), RED);
  win.show_text("Score: " + convert_int_to_string(score) , 24 , 10 , BLACK , "FreeSans.ttf" , 20);
}

void draw_energy_score (window&win , int score , int live , int energy) {
  win.fill_rect(20,10,150,40,CYAN);
  win.show_text("Score: " + convert_int_to_string(score) , 24 , 10 , BLACK , "FreeSans.ttf" , 20);
  win.fill_rect(720,10,100,30,CYAN);
  win.show_text("Energy: " + convert_int_to_string(energy) , 724 , 10 , BLACK , "FreeSans.ttf" , 16);
  win.fill_rect(1420,10,100,30,CYAN);
  win.show_text("Lives: " + convert_int_to_string(live) , 1424 , 10 , BLACK , "FreeSans.ttf" , 16);
}

void draw_particles(window& win , vector<Particle>& particles) {
  for (int i = 0; i < particles.size(); ++i)
  {
    win.draw_png(IMG_PARTICLE , particles[i].x - (particles[i].width/2)*cos((particles[i].angle*PI)/180)-particles[i].width/2  , 
                particles[i].y + (particles[i].height/2)*sin((particles[i].angle*PI)/180) - particles[i].height/2 , 
                particles[i].width , particles[i].height , -particles[i].angle  );
  }
}

void draw_shoots (window& win , vector<Shoot> shoots) {
  for (int i = 0; i < shoots.size(); ++i)
  {
    win.draw_png(IMG_SHOOT , shoots[i].x - (shoots[i].width/2)*cos((shoots[i].angle*PI)/180)-shoots[i].width/2  ,
                 shoots[i].y + (shoots[i].height/2)*sin((shoots[i].angle*PI)/180) - shoots[i].height/2 , shoots[i].width , 
                 shoots[i].height , -shoots[i].angle );
  }
}

void draw_lasers (window& win , vector<Laser> lasers) {
  for (int i = 0; i < lasers.size(); ++i)
  {
    win.draw_png(IMG_LASER , lasers[i].x - (lasers[i].width/2)*cos((lasers[i].angle*PI)/180)-lasers[i].width/2  ,
                 lasers[i].y + (lasers[i].height/2)*sin((lasers[i].angle*PI)/180) - lasers[i].height/2 , lasers[i].width , 
                 lasers[i].height , -lasers[i].angle );
  }
}



void check_shoots(vector<Shoot>& shoots) {
  for(int i=0 ;i<shoots.size();i++){
    if(shoots[i].x > WINDOW_WIDTH || shoots[i].x < 1 || shoots[i].y > WINDOW_HEIGHT || shoots[i].y < 1 ) {
      shoots.erase(shoots.begin()+i);
      i--;
    }


  }
}

void check_lasers(vector<Laser>& lasers) {
  for(int i=0 ;i<lasers.size();i++){
    if(lasers[i].x > WINDOW_WIDTH || lasers[i].x < 1 || lasers[i].y > WINDOW_HEIGHT || lasers[i].y < 1 ) {
      lasers.erase(lasers.begin()+i);
      i--;
    }


  }
}

bool check_collided (Diamond& diamond , Shoot& shoot) {
  int center_x = diamond.x - diamond.width/2 * cos(diamond.angle*PI/180);
  int center_y = diamond.y + diamond.height/2 * sin(diamond.angle*PI/180);

  
  if (pow(center_x - shoot.x , 2) + pow(center_y - shoot.y , 2) < 35*35 )
    return true;
  return false;
}

bool check_collided_lasers (Diamond& diamond , Laser& laser) {
  int center_x = diamond.x - diamond.width/2 * cos(diamond.angle*PI/180);
  int center_y = diamond.y + diamond.height/2 * sin(diamond.angle*PI/180);

  if (pow(center_x - laser.x , 2) + pow(center_y - laser.y , 2) < 35*35 )
    return true;
  return false;
}

int collide_shoot_with_diamonds (Shoot& shoot , vector<Diamond>& diamonds) {
  for (int i = 0; i < diamonds.size() ; ++i)
  {
    if (check_collided(diamonds[i] , shoot))
      return i;
  }
  return NOT_COLLIDING;
}

vector<int> collide_laser_with_diamonds (Laser& laser , vector<Diamond>& diamonds) {
  vector<int> result;
  for (int i = 0; i < diamonds.size() ; ++i)
  {
    if (check_collided_lasers(diamonds[i] , laser))
      result.push_back(i);
  }
  return result;
}


void birth_particle (vector<Particle>& particles , Diamond& diamond) {
  int number = (rand() % 5) + 1;
  for (int i = 0; i < number; ++i)
  {
    particles.push_back(create_particle(diamond.x , diamond.y , 2 , 2 ,20 , 12 , (int)(rand() % 360),500*TICK_DURATION));
  }
}

void kill_all_diamonds(vector<Diamond>& diamonds , vector<Particle>& particles ,int& score , int& energy , int adding ,vector<Killed_Diamond>& killed_diamonds) {
  for (int i = 0; i < diamonds.size(); ++i)
  {
    birth_particle(particles , diamonds[i]);
    score += adding;
    killed_diamonds.push_back(create_killed_diamond(diamonds[i]));
  }
  energy += diamonds.size();
  diamonds.clear();

}

void manage_collision_with_shoots (vector<Diamond>& diamonds , vector<Shoot>& shoots , vector<Particle>& particles , int& score , int adding , int& energy , vector<Killed_Diamond>& killed_diamonds) {
  for (int i = 0; i < shoots.size(); ++i)
  {
    int position = collide_shoot_with_diamonds(shoots[i] , diamonds);
    if(position != NOT_COLLIDING) {
      shoots.erase(shoots.begin() + i);
      score += adding;
      energy += 1;
      birth_particle(particles , diamonds[position]);
      killed_diamonds.push_back(create_killed_diamond(diamonds[position]));
      diamonds.erase(diamonds.begin() + position);
      i = i - 1;
      
    }
  }
}

void manage_collision_with_lasers (vector<Diamond>& diamonds , vector<Laser>& lasers , vector<Particle>& particles , int& score , int adding , int& energy , vector<Killed_Diamond>& killed_diamonds) {
  for (int i = 0; i < lasers.size(); ++i)
  {
    vector<int> position = collide_laser_with_diamonds(lasers[i] , diamonds);
    if(position.size() > 0) {
      for (int j = 0; j < position.size(); ++j)
      {
        birth_particle(particles , diamonds[position[j] - j]);
        killed_diamonds.push_back(create_killed_diamond(diamonds[position[j]]));
        diamonds.erase(diamonds.begin() + position[j] - j);
        score += adding;
        energy += 1;
      
      }
      
    }
  }
}



void collide_particle_horizontal_border(Particle& particle) {
  if (particle.y<= 0 || particle.y > (WINDOW_HEIGHT - particle.height) )
    particle.v_y = -particle.v_y;
}

void collide_particle_vertical_border(Particle& particle)
{
  if (particle.x <= 0 || particle.x > (WINDOW_WIDTH - particle.width) )
    particle.v_x = -particle.v_x;
}


void move_shoots(vector<Shoot>& shoots) {
  for(int i = 0; i < shoots.size(); i++){
    shoots[i].x = shoots[i].x + shoots[i].v_x * cos(shoots[i].angle*PI / 180);
    shoots[i].y = shoots[i].y - shoots[i].v_y * sin(shoots[i].angle*PI / 180);
  }
}

void move_lasers(vector<Laser>& lasers) {
  for(int i = 0; i < lasers.size(); i++){
    lasers[i].x = lasers[i].x + lasers[i].v_x * cos(lasers[i].angle*PI / 180);
    lasers[i].y = lasers[i].y - lasers[i].v_y * sin(lasers[i].angle*PI / 180);
  }
}

void move_particles (vector<Particle>& particles) {
  for (int i = 0; i < particles.size(); ++i)
  {
    particles[i].x = particles[i].x + particles[i].v_x * cos(particles[i].angle*PI / 180);
    particles[i].y = particles[i].y - particles[i].v_y * sin(particles[i].angle*PI / 180);

  }
}

void absorb_particle (vector<Particle>& particles , Drone& drone ,int& score, int adding , int& energy) {
  for (int i = 0; i < particles.size(); ++i)
  {
    if ((abs(particles[i].x - drone.x) < abs(drone.width * cos(drone.ati * PI /180)) + 100 ) && 
      (abs(particles[i].y - drone.y) < abs(drone.height * sin(drone.ati * PI /180)) + 100 )) {
      if ((abs(particles[i].x - drone.x) < abs(drone.width * cos(drone.ati * PI /180)) + 5 ) && 
      (abs(particles[i].y - drone.y) < abs(drone.height * sin(drone.ati * PI /180)) + 5 )) {
      particles.erase(particles.begin() + i);
      score += adding;
      energy += 1;

      } else {
      particles[i].angle = atan2(drone.y - particles[i].y , drone.x - particles[i].x ) * 180 / PI;
      if (particles[i].angle < 0)
        particles[i].angle = - particles[i].angle;
      else
        particles[i].angle = 360 - particles[i].angle;
        particles[i].x = particles[i].x + abs(particles[i].v_x) * cos(particles[i].angle*PI/180);
        particles[i].y = particles[i].y - abs(particles[i].v_y) * sin(particles[i].angle*PI/180);

      }

    }
  }
   
}

void move_diamond_x (Diamond& diamond , int target_x) {
  if (diamond.x > target_x)
  {
    if (diamond.x - target_x > diamond.v_x)
    {
      diamond.x = diamond.x + diamond.v_x * cos(diamond.angle*PI/180);
      
    } 
    else 
    {
      diamond.x = target_x;
    }
  }
  else
  {
    if (target_x - diamond.x > diamond.v_x)
    {
      diamond.x = diamond.x + diamond.v_x * cos(diamond.angle*PI/180) ;
    }
    else 
    {
      diamond.x = target_x;
    }
  }
}

void move_diamond_y (Diamond& diamond , int target_y) {
  if (diamond.y > target_y)
  {
    if (diamond.y - target_y > diamond.v_y)
    {
      diamond.y = diamond.y - diamond.v_y * sin(diamond.angle*PI/180);
      
    } 
    else 
    {
      diamond.y = target_y;
    }
  }
  else
  {
    if (target_y - diamond.y > diamond.v_y)
    {
      diamond.y = diamond.y - diamond.v_y * sin(diamond.angle*PI/180);
    }
    else 
    {
      diamond.y = target_y;
    }
  }
}

void move_drone_x(Drone& drone , int mouse_x) {
  if (drone.x > mouse_x)
  {
    if (drone.x - mouse_x < 5)
      return;
    if (drone.x - mouse_x > drone.v_x)
    {
      drone.x = drone.x + drone.v_x * cos(drone.ati*PI/180);
      
    } 
    else 
    {
      drone.x = mouse_x;
    }
  }
  else
  {
    if (mouse_x - drone.x < 5)
      return;
    if (mouse_x - drone.x > drone.v_x)
    {
      drone.x = drone.x + drone.v_x * cos(drone.ati*PI/180) ;
    }
    else 
    {
      drone.x = mouse_x;
    }
  }
  drone.x_h = drone.x+(drone.width/2)*cos(drone.ati*PI/180);
}

void move_drone_y(Drone& drone , int mouse_y) {
  if (drone.y > mouse_y)
  {
    if (drone.y - mouse_y < 5)
      return;
    if (drone.y - mouse_y > drone.v_y)
    {
      drone.y = drone.y - drone.v_y  *sin(drone.ati*PI/180) ;
      
    } 
    else 
    {
      drone.y = mouse_y;
    
    }
  }
  else
  {
    if(mouse_y - drone.y < 5)
      return;
    if (mouse_y - drone.y > drone.v_y)
    {
      drone.y = drone.y - drone.v_y * sin(drone.ati*PI/180)  ;
    }
    else 
    {
      drone.y = mouse_y;
    }
    drone.y_h = drone.y+(drone.height/2)*sin(drone.ati*PI/180);
  }
  
}
void draw_string(window& win, string text) {

  win.show_text(text, 100, 100, WHITE, FONT_FREESANS, 30);
}



void draw_drone(window& win , Drone& drone) {
  
  win.draw_png(IMG_DRONE, drone.x - (drone.width/2)*cos((drone.ati*PI)/180)-drone.width/2  , 
              drone.y + (drone.height/2)*sin((drone.ati*PI)/180) - drone.height/2 , 
              drone.width , drone.height , -drone.ati + 90 );
}

void draw_laser_drone(window& win , Drone& drone) {
  
  win.draw_png(IMG_LASER_DRONE, drone.x - (drone.width/2)*cos((drone.ati*PI)/180)-drone.width/2  , 
              drone.y + (drone.height/2)*sin((drone.ati*PI)/180) - drone.height/2 , 
              drone.width , drone.height , -drone.ati + 90 );
}

void draw_diamonds(window& win , vector<Diamond>& diamonds) {
  for (int i = 0; i < diamonds.size(); ++i)
  {
    win.draw_png(IMG_DIAMOND , diamonds[i].x - (diamonds[i].width/2)*cos((diamonds[i].angle*PI)/180)-diamonds[i].width/2  , 
                diamonds[i].y + (diamonds[i].height/2)*sin((diamonds[i].angle*PI)/180) - diamonds[i].height/2 , 
                diamonds[i].width , diamonds[i].height , -diamonds[i].angle  );
  }
  
}

void draw_killed_diamonds(window& win , vector<Killed_Diamond>& killed_diamonds) {
  for (int i = 0; i < killed_diamonds.size(); ++i)
  {
    if(killed_diamonds[i].ttl == 3)
      win.draw_png(IMG_BOOM_DIAMOND , killed_diamonds[i].x - (killed_diamonds[i].width/2)*cos((killed_diamonds[i].angle*PI)/180)-killed_diamonds[i].width/2  , 
                  killed_diamonds[i].y + (killed_diamonds[i].height/2)*sin((killed_diamonds[i].angle*PI)/180) - killed_diamonds[i].height/2 , 
                  killed_diamonds[i].width/2 , killed_diamonds[i].height/2 , -killed_diamonds[i].angle  );
    if(killed_diamonds[i].ttl == 2)
      win.draw_png(IMG_BOOM_DIAMOND , killed_diamonds[i].x - (killed_diamonds[i].width/2)*cos((killed_diamonds[i].angle*PI)/180)-killed_diamonds[i].width/2  , 
                  killed_diamonds[i].y + (killed_diamonds[i].height/2)*sin((killed_diamonds[i].angle*PI)/180) - killed_diamonds[i].height/2 , 
                  killed_diamonds[i].width , killed_diamonds[i].height , -killed_diamonds[i].angle  );
    if(killed_diamonds[i].ttl == 1)
      win.draw_png(IMG_BOOM_DIAMOND , killed_diamonds[i].x - (killed_diamonds[i].width/2)*cos((killed_diamonds[i].angle*PI)/180)-killed_diamonds[i].width/2  , 
                  killed_diamonds[i].y + (killed_diamonds[i].height/2)*sin((killed_diamonds[i].angle*PI)/180) - killed_diamonds[i].height/2 , 
                  killed_diamonds[i].width/2 , killed_diamonds[i].height/2 , -killed_diamonds[i].angle  );
    if(killed_diamonds[i].ttl == 0)
      win.draw_png(IMG_BOOM_DIAMOND , killed_diamonds[i].x - (killed_diamonds[i].width/2)*cos((killed_diamonds[i].angle*PI)/180)-killed_diamonds[i].width/2  , 
                  killed_diamonds[i].y + (killed_diamonds[i].height/2)*sin((killed_diamonds[i].angle*PI)/180) - killed_diamonds[i].height/2 , 
                  killed_diamonds[i].width/4 , killed_diamonds[i].height/4 , -killed_diamonds[i].angle  );
    
    
  }
  
}

void process_killed_diamonds(vector<Killed_Diamond>& killed_diamonds , int& time) {
  if (time == 10){
    for (int i = 0; i < killed_diamonds.size(); ++i)
    {
      killed_diamonds[i].ttl--;
      if (killed_diamonds[i].ttl < 0)
      {
        killed_diamonds.erase(killed_diamonds.begin() + i);
        i--;
      }
    }
    time = 0;
  }
}

void diamond_calculate_angle (Diamond& diamond , int target_x , int target_y) {
  double dist_x = target_x - diamond.x;
  double dist_y = target_y - diamond.y;
  if (pow(dist_x,2) + pow(dist_y,2) < 40) {
    return;
  }
  diamond.angle = atan2(dist_y , dist_x ) * 180 / PI;
  if (diamond.angle < 0)
    diamond.angle = - diamond.angle;
  else
    diamond.angle = 360 - diamond.angle;
}

void calculate_angle(Drone& drone , int mouse_x , int mouse_y) {
  double dist_x = mouse_x - drone.x;
  double dist_y = mouse_y - drone.y;
  if (pow(dist_x,2) + pow(dist_y,2) < 40)
  {
    return;
  }
  drone.ati = atan2(dist_y , dist_x) * 180 / PI;
  if (drone.ati < 0)
  {
    drone.ati = - drone.ati;
  } else {
    drone.ati = 360 - drone.ati;
  }
}

string prepare_output_text(string input_string) {
  return "  Your name: " + input_string;
}

void erase_last_char(string& input_string) {
  if(input_string.size() > 0)
      input_string.erase(input_string.size() - 1);
}

void add_char(string& input_string, char c) {
  if(input_string.size() < USER_INPUT_SIZE_MAX)
    input_string += c;
}


void mover(Drone& drone , int mouse_x , int mouse_y) {
    move_drone_x(drone,mouse_x);
    move_drone_y(drone,mouse_y);
}

void process_drone (window& win ,bool& quit_flag , Drone& drone , int& mouse_x , int& mouse_y , Event event) {

 if (event.type() == MMOTION)
  {   
    mouse_x = event.mouseX();
    mouse_y = event.mouseY();

    
  }
  if (event.type() == KEY_PRESS)
  {
    if (event.pressedKey() == QUIT)
    {
      quit_flag = true;
    }
  }
}

void process_particles(window& win, vector<Particle>& particles) {
  move_particles(particles);
  for (int i = 0; i < particles.size(); ++i)
  {
    particles[i].time -= TICK_DURATION;
    if (particles[i].time < 0) {
      particles.erase(particles.begin() + i);
      i--;
    }

    else {
      collide_particle_vertical_border(particles[i]);
      collide_particle_horizontal_border(particles[i]);
    }
  }
}

void process_shoots (window& win , vector<Shoot>& shoots , Event event , Drone drone) {
  if (event.type() == LRELEASE)
    shoots.push_back(create_shoot(drone.x , drone.y , 20 , 20 , 19 , 16 , drone.ati));
  move_shoots(shoots);
}

void process_lasers (window& win , vector<Laser>& lasers , Event event , Drone drone , int& energy) {
  if ((event.type() == LRELEASE) && (energy > 5)) {
    lasers.push_back(create_laser(drone.x , drone.y , 30 , 30 , 25 , 4 , drone.ati));
    energy -= 5;
  }
  move_lasers(lasers);
}



void birth_diamond ( vector<Diamond>& diamonds , int max_number , int probability , Drone drone) {
  int prob = rand() % 100;
  if (prob < probability)
  {
    if (diamonds.size() < max_number)
    {
      int pos_x = ((double) rand() / (RAND_MAX)) * WINDOW_WIDTH;
      int pos_y = ((double) rand() / (RAND_MAX)) * WINDOW_HEIGHT;
      int center_x = drone.x - drone.width/2 * cos(drone.ati*PI/180);
      int center_y = drone.y + drone.height/2 * sin(drone.ati*PI/180);
      while (pow(center_x - pos_x,2) + pow(center_y - pos_y,2) < 80*80) {
        pos_x = ((double) rand() / (RAND_MAX)) * WINDOW_WIDTH;
        pos_y = ((double) rand() / (RAND_MAX)) * WINDOW_HEIGHT;
      }

      diamonds.push_back(create_diamond(pos_x,pos_y, 1 , 1 , 50 , 38));
    }
  }
}

void mover_diamond (vector<Diamond>& diamonds , Drone& drone) {
  for (int i = 0; i < diamonds.size() ; i++) {
    diamond_calculate_angle(diamonds[i] , drone.x_h , drone.y_h);
    move_diamond_x(diamonds[i] , drone.x);
    move_diamond_y(diamonds[i] , drone.y);
  }
}

void check_threshold(int score , int& max_diamonds , int threshold , int original_max_diamond) {
  if (max_diamonds < original_max_diamond + (score/threshold))
    max_diamonds++;
}

void process_input (window& win, bool& quit_flag, string& input_string) {
  Event event = win.pollForEvent();

  if(event.type() == KEY_PRESS) {
    if(event.pressedKey() == BACK_SPACE)
      erase_last_char(input_string);
    else {
      if(event.pressedKey() == RETURN)
        quit_flag = true;
      else
        add_char(input_string, event.pressedKey());
    }
  }
}


string perform_scoring_menu (window& win , string& input_string , int score) {
  bool quit_flag = false;

  while (!quit_flag) {
    win.clear();
    draw_scoring_menu(win , score);
    draw_string(win , prepare_output_text(input_string));
    win.update_screen();
    Delay(TICK_DURATION);
    process_input (win,quit_flag , input_string);

  }
  return input_string;
}

int run_game(window& win , int points , int lives , int mode) {
  if (lives == 0)
    return 0;
  int energy = 0;
  Drone drone = create_drone(50 , 60 , 10 ,10, 65 , 60);
  bool quit_flag = false;
  int mouse_x = 50;
  int mouse_y = 60;
  int laser_mode = 0;
  int last_x,last_y;
  int score = points;
  int probability;
  int max_diamond;
  int original_max_diamond;
  int particle_point;
  int diamond_point;
  int threshold;
  int time = 0;
  if (mode == EASY)
  {
    probability = EASY_PROBABILITY;
    max_diamond = EASY_MAX_DIAMOND;
    original_max_diamond = EASY_MAX_DIAMOND;
    particle_point = EASY_PARTICLE_POINT;
    diamond_point = EASY_DIAMOND_POINT;
    threshold = EASY_THRESHOLD;
  } else if (mode == NORMAL) {
    probability = NORMAL_PROBABILITY;
    max_diamond = NORMAL_MAX_DIAMOND;
    original_max_diamond = NORMAL_MAX_DIAMOND;
    particle_point = NORMAL_PARTICLE_POINT;
    diamond_point = NORMAL_DIAMOND_POINT;
    threshold = NORMAL_THRESHOLD;
  } else {
    probability = HARD_PROBABILITY;
    max_diamond = HARD_MAX_DIAMOND;
    original_max_diamond = HARD_MAX_DIAMOND;
    particle_point = HARD_PARTICLE_POINT;
    diamond_point = HARD_DIAMOND_POINT;
    threshold = HARD_THRESHOLD;
  }
  vector<Diamond> diamonds;
  vector<Killed_Diamond> killed_diamonds;
  vector<Shoot> shoots;
  vector<Laser> lasers;
  vector<Particle> particles;
  while(!quit_flag) {

    Event event = win.pollForEvent();
    last_x = drone.x;
    last_y = drone.y;
    if (event.type() == KEY_PRESS) {
      if(event.pressedKey() == TO_LASER) {
        laser_mode = 1;
        last_x = drone.x;
        last_y =drone.y;
      }
      if (event.pressedKey() == TO_NORMAL) {
        laser_mode = 0;
        drone.x = last_x;
        drone.y = last_y;
      }
      if ((event.pressedKey() == BOMB) && (energy > 200) ) {
        kill_all_diamonds(diamonds , particles , score , energy , particle_point , killed_diamonds);
        energy -= 200;
      }
    }

    calculate_angle(drone,mouse_x , mouse_y);
    if (laser_mode == 0)
      mover(drone , mouse_x , mouse_y);
      
    
    birth_diamond(diamonds , max_diamond , probability , drone);
    mover_diamond(diamonds , drone);
    if (laser_mode == 0)
      process_shoots(win , shoots , event , drone);
    else
      process_lasers(win , lasers, event , drone , energy);
    process_particles(win , particles);
    absorb_particle(particles,drone,score , particle_point , energy);
    
    win.clear();
    draw_background(win);
    draw_energy_score(win , score , lives , energy);
    if (laser_mode == 0) 
      draw_drone(win, drone);
    else
      draw_laser_drone(win , drone);
    draw_diamonds(win,diamonds);
    draw_killed_diamonds(win , killed_diamonds );
    draw_shoots(win,shoots);
    draw_lasers(win, lasers);
    draw_particles(win,particles);
    
    win.update_screen();

    Delay(TICK_DURATION);
    time ++;
    process_killed_diamonds(killed_diamonds , time);
    process_drone (win, quit_flag, drone , mouse_x , mouse_y , event);
    check_shoots(shoots);
    check_lasers(lasers);
    manage_collision_with_shoots(diamonds,shoots,particles,score,diamond_point , energy , killed_diamonds);
    manage_collision_with_lasers(diamonds,lasers,particles,score,diamond_point , energy , killed_diamonds);
    check_threshold(score,max_diamond,threshold,original_max_diamond);
    if (collision_of_drone_diamonds(diamonds , drone))
    {
      win.clear();
      draw_background(win);
      draw_energy_score(win , score , lives , energy);
    
      win.draw_png(IMG_BOOM , drone.x - (drone.width/2)*cos((drone.ati*PI)/180)-drone.width/2  , 
                drone.y + (drone.height/2)*sin((drone.ati*PI)/180) - drone.height/2 , 
                drone.width/2 , drone.height/2 , -drone.ati  );
      draw_diamonds(win,diamonds);
      draw_shoots(win,shoots);
      draw_lasers(win, lasers);
      draw_particles(win,particles);
      win.update_screen();
      Delay(TICK_DURATION * 100);
      
      win.clear();
      draw_background(win);
      draw_energy_score(win , score , lives , energy);
    
      win.draw_png(IMG_BOOM , drone.x - (drone.width/2)*cos((drone.ati*PI)/180)-drone.width/2  , 
                drone.y + (drone.height/2)*sin((drone.ati*PI)/180) - drone.height/2 , 
                drone.width , drone.height , -drone.ati  );
      draw_diamonds(win,diamonds);
      draw_shoots(win,shoots);
      draw_lasers(win, lasers);
      draw_particles(win,particles);
      win.update_screen();
      Delay(TICK_DURATION * 100);
      
      win.clear();
      draw_background(win);
      draw_energy_score(win , score , lives , energy);
    
      win.draw_png(IMG_BOOM , drone.x - (drone.width/2)*cos((drone.ati*PI)/180)-drone.width/2  , 
                drone.y + (drone.height/2)*sin((drone.ati*PI)/180) - drone.height/2 , 
                drone.width/2 , drone.height/2 , -drone.ati  );
      draw_diamonds(win,diamonds);
      draw_shoots(win,shoots);
      draw_lasers(win, lasers);
      draw_particles(win,particles);
      win.update_screen();
      Delay(TICK_DURATION * 100);
      
      win.clear();
      draw_background(win);
      draw_energy_score(win , score , lives , energy);
    
      win.draw_png(IMG_BOOM , drone.x - (drone.width/2)*cos((drone.ati*PI)/180)-drone.width/2  , 
                drone.y + (drone.height/2)*sin((drone.ati*PI)/180) - drone.height/2 , 
                drone.width/4 , drone.height/4 , -drone.ati  );
      draw_diamonds(win,diamonds);
      draw_shoots(win,shoots);
      draw_lasers(win, lasers);
      draw_particles(win,particles);
      win.update_screen();
      Delay(TICK_DURATION * 100);
      
      
      break;
    }
    
    
  }
  if(!quit_flag)
    return run_ready_menu(win , score , lives - 1 , mode);
  return score;

}

void draw_leader_board_shapes (window& win , vector<Top_people> tops) {
  win.draw_line(100 , 100 , 1100 , 100);
  win.draw_line(100 , 200 , 1100 , 200);
  win.draw_line(100 , 300 , 1100 , 300);
  win.draw_line(100 , 400 , 1100 , 400);
  win.draw_line(100 , 500 , 1100 , 500);
  win.draw_line(100 , 600 , 1100 , 600);
  win.draw_line(100 , 50 , 100 , 650);
  win.draw_line(600 , 50 , 600 , 650);
  win.show_text("Name ", 250 , 50 , WHITE, "FreeSans.ttf", 30);
  win.show_text("Score " , 750 , 50 , WHITE , "FreeSans.ttf" , 30);
  for (int i = 0; i < tops.size() ; ++i)
  {
    win.show_text(tops[i].name , 250 , 50 + 100 * (i + 1) , WHITE , "FreeSans.ttf" , 30);
    win.show_text(convert_int_to_string(tops[i].score) , 750 , 50 + 100 * (i + 1) , WHITE , "FreeSans.ttf" , 30);
  }

  win.fill_rect(WINDOW_WIDTH / WIDTH_PART , 5 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , RED);
  win.show_text("BACK ", WINDOW_WIDTH/2, 13 * WINDOW_HEIGHT/15, WHITE, "FreeSans.ttf", 30);




}

void draw_first_menu_shapes(window& win , int command) {
  if (command == 1)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 6, 6* WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, RED);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, 3 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART , 5 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
  }
  if (command == 2)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 6,6 * WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART,3 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , RED);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART ,5 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);

  }
  if (command == 3)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 6,6 * WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART,3 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART , 5 * WINDOW_HEIGHT / 6 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , RED);

  }
  win.show_text("New Game", WINDOW_WIDTH/2, WINDOW_HEIGHT/5, WHITE, "FreeSans.ttf", 30);
  win.show_text("LeaderBoard", WINDOW_WIDTH/2,8 * WINDOW_HEIGHT/ 15, WHITE, "FreeSans.ttf", 30);
  win.show_text("EXIT", WINDOW_WIDTH/2, 13 * WINDOW_HEIGHT/15, WHITE, "FreeSans.ttf", 30);
}

void draw_second_menu_shapes(window& win , int command) {
  if (command == 1)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 8, 6* WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, RED);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, 3 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART , 5 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART ,7 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
  }
  if (command == 2)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 8,6 * WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART,3 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , RED);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART ,5 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART ,7 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);


  }
  if (command == 3)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 8,6 * WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART,3 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART , 5 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , RED);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART ,7 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);


  }
  if (command == 4)
  {
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 8,6 * WINDOW_WIDTH / WIDTH_PART, WINDOW_HEIGHT / 10, BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART,3 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART , 5 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , BLUE);
    win.fill_rect(WINDOW_WIDTH / WIDTH_PART ,7 * WINDOW_HEIGHT / 8 ,6 * WINDOW_WIDTH / WIDTH_PART , WINDOW_HEIGHT / 10 , RED);


  }
  win.show_text("Easy", WINDOW_WIDTH/2, WINDOW_HEIGHT/6, WHITE, "FreeSans.ttf", 30);
  win.show_text("Normal", WINDOW_WIDTH/2,10 * WINDOW_HEIGHT/ 24, WHITE, "FreeSans.ttf", 30);
  win.show_text("Hard", WINDOW_WIDTH/2, 16 * WINDOW_HEIGHT/24, WHITE, "FreeSans.ttf", 30);
  win.show_text("Back", WINDOW_WIDTH/2, 22 * WINDOW_HEIGHT/24, WHITE, "FreeSans.ttf", 30);


}

void draw_ready_menu (window& win) {
  win.draw_bg(IMG_BACKGROUND, 0, 0);
  win.show_text("READY?", WINDOW_WIDTH/2, WINDOW_HEIGHT/2, WHITE, "FreeSans.ttf", 80);
}
void process_first_menu(window& win , int& command , bool& pressed_return) {
  Event event = win.pollForEvent();
  if (event.type() == KEY_PRESS)
  {
    if (event.pressedKey() == UP_ARROW)
    {
      command--;
      if(command < 1) {
        command = 3;
      }
    }
    if (event.pressedKey() == DOWN_ARROW)
    {
        command++;
        if (command > 3)
          command = 1;
    }
    if (event.pressedKey() == RETURN)
    {
        pressed_return = true;
    }
  }
}

void process_second_menu(window& win , int& command , bool& pressed_return) {
  Event event = win.pollForEvent();
  if (event.type() == KEY_PRESS)
  {
    if (event.pressedKey() == UP_ARROW)
    {
      command--;
      if(command < 1) {
        command = 4;
      }
    }
    if (event.pressedKey() == DOWN_ARROW)
    {
        command++;
        if (command > 4)
          command = 1;
    }
    if (event.pressedKey() == RETURN)
    {
        pressed_return = true;
    }
  }
}

void process_ready_menu(window& win , bool& command){
  Event event = win.pollForEvent();
  if(event.type() == KEY_PRESS || event.type() == RRELEASE || event.type() == LRELEASE ) {
      command = true; 
  }
}
int run_ready_menu(window& win , int& score , int live , int mode) {
  if (live < 1)
    return score;
  bool command = false;
  int result;
  while (!command) {
    win.clear();
    draw_background(win);
    draw_ready_menu(win);
    draw_energy_score(win , score , live , 0);
    win.update_screen();
    Delay(TICK_DURATION);
    process_ready_menu(win,command);
  }
  result=run_game(win , score , live , mode);
  return result;
}

int run_second_menu(window& win) {
  bool pressed_return = false;
  int command = 1;
  int result;
  int score = 0;
  int live = 3;
  while (!pressed_return) {
    win.clear();
    draw_background(win);
    draw_second_menu_shapes(win,command);
    win.update_screen();
    Delay(TICK_DURATION);
    process_second_menu(win , command , pressed_return);
  }
  if (command == 1){
    result=run_ready_menu(win , score , live , EASY);
  }
  if (command == 2){
    result = run_ready_menu(win , score , live , NORMAL);
  }
  if (command == 3) {
    result = run_ready_menu(win , score , live , HARD);
  }
  if (command == 4) {
    result = GO_BACK;
  }
  return result;
}

void process_leader_board(window& win , bool& pressed_return) {
  Event event = win.pollForEvent();
  if (event.type() == KEY_PRESS)
    if (event.pressedKey() == RETURN)
    {
      pressed_return = true;
    }
}

int run_leaderboard(window& win , vector<Top_people> tops) {
  bool pressed_return = false;
  while (!pressed_return) {
    win.clear();
    draw_background(win);
    draw_leader_board_shapes(win , tops);
    win.update_screen();
    process_leader_board(win , pressed_return);
  }
  return GO_BACK;

}

int run_first_menu(window& win , vector<Top_people> tops) {
  bool pressed_return = false;
  int command = 1;
  int result;
  while (!pressed_return) {
    win.clear();
    draw_background(win);
    draw_first_menu_shapes(win,command);
    win.update_screen();
    Delay(TICK_DURATION);
    process_first_menu(win , command , pressed_return);
  }
  if (command == 1) {
    result=run_second_menu(win);
  }
  if (command == 2) {
    result = run_leaderboard(win , tops);
  }
  if (command == 3) {
    result = EXIT;
  }
  return result;
}


void read_from_file (vector<Top_people>& tops) {
  string line;
  tops.clear();
  ifstream input("score.txt");
  while (getline(input,line)) {
    if (line.substr(0,line.find(' ')) == "")
      continue;
    Top_people new_top;
    new_top.name = line.substr(0,line.find(' '));
    new_top.score = convert_string_to_int(line.substr(line.find(' ')+ 1));
    tops.push_back(new_top);
  }
  input.close();
}

void write_to_file (vector<Top_people>& tops) {
  ofstream output("score.txt");
  for (int i = 0; i < tops.size() ; ++i)
  {
    output << tops[i].name << " " << convert_int_to_string(tops[i].score) << endl;
  }
  output.close();
}


int main()
{
  
  int result;
  vector<Top_people> tops; 
  read_from_file(tops);
  
  window win(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  while (true) {
    result = run_first_menu(win , tops);
    while (result == GO_BACK) {
      result = run_first_menu(win , tops);
    }
    if (result == EXIT)
      break;
    string name;
    perform_scoring_menu(win , name , result);
    process_tops(tops , result , name);
    
  }
  write_to_file(tops);
  
  
}
