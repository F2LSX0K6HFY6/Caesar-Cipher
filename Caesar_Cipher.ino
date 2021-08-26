String password;
String shifted;
int len =0;  //length of the password
#define led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pinMode (13,OUTPUT);
//////////////////////////entering the actual password//////////////////////////////////////////////
 Serial.println("Enter the actual password");
  while (Serial.available()==0)
    {                }     //wait for the user entering the password
    
       password=Serial.readString();
       Serial.println(password);

       len=password.length();
        delay(500);
       shift(password,len);      //calling the function to shift the input

}

void loop() {
  // put your main code here, to run repeatedly:
 

  
    Serial.println("Enter the shifted version");
    while (Serial.available()==0) //wait for the user entering the encrypted password
    {}
   shifted=Serial.readString();
   delay(50);
  Serial.println(shifted);

 ////////////////in case the password is correct/////////////////////
    if (shifted==password)
   {shift(password,len); 
   ////led is turned on for 3 seconds///
    digitalWrite(led,HIGH);
    delay(3000);
    digitalWrite(led,LOW);
    delay(3000);
    
    }

////////////////in case the password is incorrect/////////////////////    
    else
    {for (int y=0;y<3;y++)
{
  digitalWrite(led, HIGH);  ////led is blinking for 3 seconds///
  delay(1000); 
  
  digitalWrite(led, LOW);
  delay(1000); 
}
      }
   
}

void shift (String &pass,int len)
{
  
    for (int i=0;i<len;i++)
  {
    
        for(int j=0;j<1;j++)
        {
          if (pass[i]=='z')
          pass[i]='a';

          else if (pass[i]=='Z')
              pass[i]='A';
           else
                         pass[i]++;   
           
        }
   }
}
