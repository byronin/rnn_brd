
byte pro_sh = 4 , pro_ds = 6 , pro_st = 5 ;
int l_e_f_t_m_1 = 3 , l_e_f_t_m_2 = 11 , r_i_g_h_t_m_1 = 9 , r_i_g_h_t_m_2 = 10 ;
int pro_short_brake = 1 ;

int button_1 = 8 , button_2 = 7 , button_3 = 12 , bt_1 , bt_2 , bt_3 , number = 18 ;
boolean value =  0;
void setup() {

  pinMode( button_1 , INPUT);
  pinMode( button_2 , INPUT);
  pinMode( button_3 , INPUT);

  pinMode(pro_sh , OUTPUT);
  pinMode(pro_ds , OUTPUT);
  pinMode(pro_st , OUTPUT);
  pinMode(l_e_f_t_m_1 , OUTPUT);
  pinMode(l_e_f_t_m_2 , OUTPUT);
  pinMode(r_i_g_h_t_m_1 , OUTPUT);
  pinMode(r_i_g_h_t_m_2 , OUTPUT);

  data_write(0, 0, 0, 0, 0, 0, 0, 1);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 1, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 1, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 1, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 1, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 1, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 1, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(1, 0, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 0, 1);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 1, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 1, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 1, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 1, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 1, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 1, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(1, 0, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 0, 1);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 1, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 1, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 1, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 1, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 1, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 1, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(1, 0, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 0, 1);
  delay(80);
  data_write(0, 0, 0, 0, 0, 0, 1, 0);
  delay(80);
  data_write(0, 0, 0, 0, 0, 1, 0, 0);
  delay(80);
  data_write(0, 0, 0, 0, 1, 0, 0, 0);
  delay(80);
  data_write(0, 0, 0, 1, 0, 0, 0, 0);
  delay(80);
  data_write(0, 0, 1, 0, 0, 0, 0, 0);
  delay(80);
  data_write(0, 1, 0, 0, 0, 0, 0, 0);
  delay(80);
  data_write(1, 0, 0, 0, 0, 0, 0, 0);
  delay(80);

}

void loop() {

  if (bt_3 != digitalRead(button_3)) {
    if (bt_3 == HIGH) {
      if (value == 1) {
        value = 0;
      } else {
        value = 1;
      }
    }
    bt_3 =  digitalRead(button_3);
  }

  if (bt_1 != digitalRead(button_1)) {
    if (bt_1 == HIGH) {
      number = number + 1 ;
    }
    bt_1 =  digitalRead(button_1);
  }

  if (bt_2 != digitalRead(button_2)) {
    if (bt_2 == HIGH) {
      number = number - 1 ;
    }
    bt_2 =  digitalRead(button_2);
  }

  if (value == 1) {
    drive_dc(5.26 * number , 5.26 * number);
  } else if (value == 0) {
    drive_dc(-5.26 * number , -5.26 * number);
  }




  if (number > 19) {
    number = 0 ;
  }
  if (number < 0) {
    number = 19 ;
  }

  segment_write(number);

}
void drive_dc(float   left_m_pwm , float right_m_pwm) {
  left_m_pwm = 2.55 * left_m_pwm ;
  right_m_pwm = 2.55 * right_m_pwm ;
  if (pro_short_brake == 1 & left_m_pwm == 0) {

    analogWrite(l_e_f_t_m_1 , 255);
    analogWrite(l_e_f_t_m_2 , 255);

  } else if (left_m_pwm < 0) {
    left_m_pwm = -1 * left_m_pwm ;
    analogWrite(l_e_f_t_m_1 , 0);
    analogWrite(l_e_f_t_m_2 , left_m_pwm);

  } else if (left_m_pwm > 0) {

    analogWrite(l_e_f_t_m_1 , left_m_pwm);
    analogWrite(l_e_f_t_m_2 , 0);

  } else if (pro_short_brake == 0 & left_m_pwm == 0) {

    analogWrite(l_e_f_t_m_1 , left_m_pwm);
    analogWrite(l_e_f_t_m_2 , left_m_pwm);

  }
  if (pro_short_brake == 1 & right_m_pwm == 0) {

    analogWrite(r_i_g_h_t_m_1 , 255);
    analogWrite(r_i_g_h_t_m_2 , 255);

  } else if (right_m_pwm < 0) {
    right_m_pwm = -1 * right_m_pwm ;
    analogWrite(r_i_g_h_t_m_1 , 0);
    analogWrite(r_i_g_h_t_m_2 , right_m_pwm);

  } else if (right_m_pwm > 0) {

    analogWrite(r_i_g_h_t_m_1 , right_m_pwm);
    analogWrite(r_i_g_h_t_m_2 , 0);

  } else if (pro_short_brake == 0 & right_m_pwm == 0) {

    analogWrite(r_i_g_h_t_m_1 , right_m_pwm);
    analogWrite(r_i_g_h_t_m_2 , right_m_pwm);

  }
}

void segment_write(int dis ) {
  if (dis == 0) {
    data_write(0, 0, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 0, 0
  } else if (dis == 1) {
    data_write(0, 0, 0, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 2) {
    data_write(0, 1, 0, 1, 1, 0, 1, 1);
    //1, 1, 0, 1, 1, 0, 1, 0
  } else if (dis == 3) {
    data_write(0, 1, 0, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 0, 1, 0
  } else if (dis == 4) {
    data_write(0, 1, 1, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 1, 1, 0
  } else if (dis == 5) {
    data_write(0, 1, 1, 0, 1, 1, 0, 1);
    //1, 0, 1, 1, 0, 1, 1, 0
  } else if (dis == 6) {
    data_write(0, 1, 1, 1, 1, 1, 0, 1);
    //1, 0, 1, 1, 1, 1, 1, 0
  } else if (dis == 7) {
    data_write(0, 0, 0, 0, 0, 1, 1, 1);
    //1, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 8) {
    data_write(0, 1, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 1, 0
  } else if (dis == 9) {
    data_write(0, 1, 1, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 1, 1, 0
  } else if (dis == 10) {
    data_write(1, 0, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 0, 0
  } else if (dis == 11) {
    data_write(1, 0, 0, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 12) {
    data_write(1, 1, 0, 1, 1, 0, 1, 1);
    //1, 1, 0, 1, 1, 0, 1, 0
  } else if (dis == 13) {
    data_write(1, 1, 0, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 0, 1, 0
  } else if (dis == 14) {
    data_write(1, 1, 1, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 1, 1, 0
  } else if (dis == 15) {
    data_write(1, 1, 1, 0, 1, 1, 0, 1);
    //1, 0, 1, 1, 0, 1, 1, 0
  } else if (dis == 16) {
    data_write(1, 1, 1, 1, 1, 1, 0, 1);
    //1, 0, 1, 1, 1, 1, 1, 0
  } else if (dis == 17) {
    data_write(1, 0, 0, 0, 0, 1, 1, 1);
    //1, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 18) {
    data_write(1, 1, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 1, 0
  } else if (dis == 19) {
    data_write(1, 1, 1, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 1, 1, 0
  }
}

void data_write(boolean data_0 , boolean data_1 , boolean data_2 , boolean data_3 , boolean data_4 , boolean data_5 , boolean data_6 , boolean data_7 ) {
  digitalWrite(pro_st , LOW);
  digitalWrite(pro_sh , LOW);
  if (data_0 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_1 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_2 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_3 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_4 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_5 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_6 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_7 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  digitalWrite(pro_st , HIGH);
  digitalWrite(pro_st , LOW);
}
