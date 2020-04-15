int matriz[16][7]={
{1,1,1,1,1,1,0},//0
{0,1,1,0,0,0,0},//1
{1,1,0,1,1,0,1},//2
{1,1,1,1,0,0,1},//3
{0,1,1,0,0,1,1},//4 
{1,0,1,1,0,1,1},//5 
{1,0,1,1,1,1,1},//6
{1,1,1,0,0,0,0},//7
{1,1,1,1,1,1,1},//8
{1,1,1,1,0,1,1},//9
{1,1,1,0,1,1,1},//A
{0,0,1,1,1,1,1},//B
{1,0,0,1,1,1,0},//C
{0,1,1,1,1,0,1},//D
{1,0,0,1,1,1,1},//E
{1,0,0,0,1,1,1},//F
};
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  int i=random(1,7);
    for(int j=0;j<7;j++){
      if(matriz[i][j]==1){
        digitalWrite(j+2,HIGH);
      }
      }
    delay(5000);
    for(int z=2;z<9;z++){
      digitalWrite(z,LOW);
    }
    delay(1000);
  
}