#include "trem.h"
#include <QtCore>
#include <pthread.h>
#include <semaphore.h>

sem_t sem0;
sem_t sem1;
sem_t sem2;
sem_t sem3;
sem_t sem4;
sem_t sem5;
sem_t sem6;

sem_t semdeadlock1;
sem_t semdeadlock2;
sem_t semdeadlock3;
sem_t semdeadlockzone1;

//Construtor
Trem::Trem(int ID, int x, int y, int velocidade){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;

    if(ID == 1){
        sem_init(&sem0, 0,1);
        sem_init(&sem1, 0,1);
        sem_init(&sem2, 0,1);
        sem_init(&sem3, 0,1);
        sem_init(&sem4, 0,1);
        sem_init(&sem5, 0,1);
        sem_init(&sem6, 0,1);

        sem_init(&semdeadlock1, 0,2);
        sem_init(&semdeadlock2, 0,2);
        sem_init(&semdeadlock3, 0,2);

        sem_init(&semdeadlockzone1, 0,3);
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(velocidade != 200){
                //deadlock 1
                if(x == 310 && y == 30){
                    sem_wait(&semdeadlockzone1);
                    sem_wait(&semdeadlock1);
                }
                if(x == 310 && y == 150){
                    sem_post(&semdeadlockzone1);
                    sem_post(&semdeadlock1);
                }
                //-------------

                if(x == 310 && y == 30){
                    sem_wait(&sem0);
                }
                if(x == 310 && y == 150){
                    sem_post(&sem0);
                }

                if(x == 330 && y == 130){
                    sem_wait(&sem2);
                }
                if(x == 180 && y == 150){
                    sem_post(&sem2);
                }

                if (y == 30 && x <330)
                    x+=10;
                else if (x == 330 && y < 150)
                    y+=10;
                else if (x > 60 && y == 150)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if(velocidade != 200){
                //deadlock 2
                if(x == 450 && y == 150){
                    sem_post(&semdeadlock2);
                }
                //-------------

                //deadlock 1
                if(x == 490 && y == 150){
                    sem_wait(&semdeadlock1);
                }

                if(x == 330 && y == 130){
                    sem_post(&semdeadlockzone1);
                    sem_post(&semdeadlock1);
                }
                //-------------

                //deadlock 3
                if(x == 580 && y == 30){
                    sem_wait(&semdeadlock2);
                    sem_wait(&semdeadlock3);
                }

                if(x == 580 && y == 150){
                    sem_post(&semdeadlock3);
                }
                //-------------

                //deadlock zone
                if(x == 600 && y == 130){
                    sem_wait(&semdeadlockzone1);
                }

                if(x == 450 && y == 150){
                    sem_post(&semdeadlockzone1);
                }
                //------------------------

                if(x == 350 && y == 150){
                    sem_wait(&sem0);
                }

                if(x == 350 && y == 30){
                    sem_post(&sem0);
                }

                if(x == 580 && y == 30){
                    sem_wait(&sem1);
                }

                if(x == 580 && y == 150){
                    sem_post(&sem1);
                }

                if(x == 490 && y == 150){
                    sem_wait(&sem3);
                }

                if(x == 330 && y == 130){
                    sem_post(&sem3);
                }

                if(x == 600 && y == 130){
                    sem_wait(&sem4);
                }

                if(x == 450 && y == 150){
                    sem_post(&sem4);
                }

                if (y == 30 && x <600)
                    x+=10;
                else if (x == 600 && y < 150)
                    y+=10;
                else if (x > 330 && y == 150)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:
            if(velocidade != 200){
                //deadlock 3
                if(x == 760 && y == 150){
                    sem_wait(&semdeadlock3);
                }

                if(x == 600 && y == 130){
                    sem_post(&semdeadlock3);
                }
                //-------------

                if(x == 620 && y == 150){
                    sem_wait(&sem1);
                }

                if(x == 620 && y == 30){
                    sem_post(&sem1);
                }

                if(x == 760 && y == 150){
                    sem_wait(&sem5);
                }

                if(x == 600 && y == 130){
                    sem_post(&sem5);
                }

                if (y == 30 && x <870)
                    x+=10;
                else if (x == 870 && y < 150)
                    y+=10;
                else if (x > 600 && y == 150)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4:
            if(velocidade != 200){
                //deadlock 2
                if(x == 470 && y == 170){
                    sem_post(&semdeadlock2);
                }
                //-------------

                //deadlock 1
                if(x == 200 && y == 170){
                    sem_wait(&semdeadlock2);
                    sem_wait(&semdeadlock1);
                }

                if(x == 350 && y == 150){
                    sem_post(&semdeadlock1);
                }
                //--------

                //zone 1
                if(x == 200 && y ==180){
                     sem_wait(&semdeadlockzone1);
                }

                if(x == 450 && y ==270){
                    sem_post(&semdeadlockzone1);
                }
                //-------------

                if(x == 200 && y == 170){
                    sem_wait(&sem2);
                }

                if(x == 350 && y == 150){
                    sem_post(&sem2);
                }

                if(x == 310 && y == 150){
                    sem_wait(&sem3);
                }

                if(x == 470 && y == 170){
                    sem_post(&sem3);
                }

                if(x == 450 && y == 150){
                    sem_wait(&sem6);
                }

                if(x == 450 && y == 270){
                    sem_post(&sem6);
                }

                if (y == 150 && x < 470)
                    x+=10;
                else if (x == 470 && y < 270)
                    y+=10;
                else if (x > 200 && y == 270)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5:
            if(velocidade != 200){
                //deadlock 2
                if(x == 490 && y == 270){
                    sem_wait(&semdeadlockzone1);
                    sem_wait(&semdeadlock2);
                }

                if(x == 490 && y == 150){
                    sem_post(&semdeadlockzone1);
                    sem_post(&semdeadlock2);
                }
                //-------------

                //deadlock 3
                if(x == 470 && y == 170){
                    sem_wait(&semdeadlock3);
                }

                if(x == 620 && y == 150){
                    sem_post(&semdeadlock3);
                }
                //-------------

                if(x == 470 && y == 170){
                    sem_wait(&sem4);
                }

                if(x == 620 && y == 150){
                    sem_post(&sem4);
                }

                if(x == 580 && y == 150){
                    sem_wait(&sem5);
                }

                if(x == 740 && y == 170){
                    sem_post(&sem5);
                }

                if(x == 490 && y == 270){
                    sem_wait(&sem6);
                }

                if(x == 490 && y == 150){
                    sem_post(&sem6);
                }

                if (y == 150 && x < 740)
                    x+=10;
                else if (x == 740 && y < 270)
                    y+=10;
                else if (x > 470 && y == 270)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::mudarVelocidade(int novaVelocidade){
    this->velocidade = novaVelocidade;
}




