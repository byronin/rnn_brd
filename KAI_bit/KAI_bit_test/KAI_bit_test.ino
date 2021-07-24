//time: 03:40
int l_e_f_t_m_1 = 10 , l_e_f_t_m_2 = 9 , r_i_g_h_t_m_1 = 3 , r_i_g_h_t_m_2 = 11 ;
int short_brake = 1 ;
void setup() {
  pinMode(l_e_f_t_m_1 , OUTPUT);
  pinMode(l_e_f_t_m_2 , OUTPUT);
  pinMode(r_i_g_h_t_m_1 , OUTPUT);
  pinMode(r_i_g_h_t_m_2 , OUTPUT);
}

void loop() {


  drive_dc(100, 100);
  delay(400);
  drive_dc(-100, -100);
  delay(400);
  drive_dc(100, -100);
  delay(400);
  drive_dc(-100, 100);
  delay(400);
  drive_dc(0, 0);
  delay(400);
  drive_dc(-10, -10);
  delay(400);
  drive_dc(10, 10);
  delay(400);
  drive_dc(0, 0);
  delay(4000);
}
void drive_dc(float   left_m_pwm , float right_m_pwm) {
  left_m_pwm = 2.55 * left_m_pwm ;
  right_m_pwm = 2.55 * right_m_pwm ;
  if (short_brake == 1 & left_m_pwm == 0) {

    analogWrite(l_e_f_t_m_1 , 255);
    analogWrite(l_e_f_t_m_2 , 255);

  } else if (left_m_pwm < 0) {

    analogWrite(l_e_f_t_m_1 , 0);
    analogWrite(l_e_f_t_m_2 , 255);

  } else if (left_m_pwm > 0) {

    analogWrite(l_e_f_t_m_1 , 255);
    analogWrite(l_e_f_t_m_2 , 0);

  } else if (short_brake == 0 & left_m_pwm == 0) {

    analogWrite(l_e_f_t_m_1 , 0);
    analogWrite(l_e_f_t_m_2 , 0);

  }
  if (short_brake == 1 & right_m_pwm == 0) {

    analogWrite(r_i_g_h_t_m_1 , 255);
    analogWrite(r_i_g_h_t_m_2 , 255);

  } else if (right_m_pwm < 0) {

    analogWrite(r_i_g_h_t_m_1 , 0);
    analogWrite(r_i_g_h_t_m_2 , 255);

  } else if (right_m_pwm > 0) {

    analogWrite(r_i_g_h_t_m_1 , 255);
    analogWrite(r_i_g_h_t_m_2 , 0);

  } else if (short_brake == 0 & right_m_pwm == 0) {

    analogWrite(r_i_g_h_t_m_1 , 0);
    analogWrite(r_i_g_h_t_m_2 , 0);

  }

}
