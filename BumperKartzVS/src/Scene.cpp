#include "Scene.hpp"

Scene::Scene():
    cam(0,0,0,0,0,1,0,1,0,0.75f,1.5f)
{
    karts[0] = &mx;
    karts[1] = &mx2;
    karts[2] = &my;
    karts[3] = &my2;

    for(int i = 0; i < 4; i++)
        arrowsP1[i] = false;
    for(int i = 0; i < 4; i++)
        arrowsP2[i] = false;

    start = std::chrono::steady_clock::now();
    angle = 0.0f;
}

Scene::~Scene(){}

void Scene::init()
{
    Kart::setTimer(start);

    mx.setPositionPoint(0,mx.getPosY(),0);
    mx2.setPositionPoint(30,mx2.getPosY(),12);
    my.setPositionPoint(10,my.getPosY(),-30);
    my2.setPositionPoint(30,my2.getPosY(),15);

    cam.display();
}

void Scene::setSinglePlayer(bool value)
{
    player = value;
}

void Scene::inputPressed(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Player 1
        case 'w': case 'W':
             arrowsP1[0] = true;
             break;
        case 's': case 'S':
             arrowsP1[1] = true;
             break;
        case 'd': case 'D':
             arrowsP1[2] = true;
             break;
        case 'a': case 'A':
             arrowsP1[3] = true;
             break;

        // Player 2
        case 'i': case 'I':
             arrowsP2[0] = true;
             break;
        case 'k': case 'K':
             arrowsP2[1] = true;
             break;
        case 'l': case 'L':
             arrowsP2[2] = true;
             break;
        case 'j': case 'J':
             arrowsP2[3] = true;
             break;
    }
}

void Scene::inputReleased(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Player 1
        case 'w': case 'W':
             arrowsP1[0] = false;
             break;
        case 's': case 'S':
             arrowsP1[1] = false;
             break;
        case 'd': case 'D':
             arrowsP1[2] = false;
             break;
        case 'a': case 'A':
             arrowsP1[3] = false;
             break;

        // Player 2
        case 'i': case 'I':
             arrowsP2[0] = false;
             break;
        case 'k': case 'K':
             arrowsP2[1] = false;
             break;
        case 'l': case 'L':
             arrowsP2[2] = false;
             break;
        case 'j': case 'J':
             arrowsP2[3] = false;
             break;
    }
}

void Scene::updateOthers()
{
    float safeDistance, distance;

    if(player)
    {
        //El kart3 ataca al kart4
        karts[2]->attack(karts[3],7);
    }

    //El kart2 "vigila" una circunferencia y si se acerca
    //una cierta distancia el jugador, ataca
    safeDistance = 15.0f;
    distance = Util::pointDistance(mx2.getPosX(),
                                     mx2.getPosY(),
                                     mx2.getPosZ(),
                                     mx.getPosX(),
                                     mx.getPosY(),
                                     mx.getPosZ());
    if(distance - (mx2.getRadious() + mx.getRadious()) < safeDistance)
    {
        karts[1]->attack(karts[0],2);
    }
    else
    {
        mx2.moveRight();
        mx2.moveRight();
        mx2.accelerateForward();
    }

    //el kart4 ataca al kart2
    karts[3]->attack(karts[1],4);
}

void Scene::updateMovement()
{
    // Update player 1
    if(arrowsP1[0])
        mx.accelerateForward();
    if(arrowsP1[1])
        mx.accelerateBackward();
    if(arrowsP1[2])
        mx.moveRight();
    if(arrowsP1[3])
        mx.moveLeft();

    if(!player)
    {
        // Update player 2
        if(arrowsP2[0])
            my.accelerateForward();
        if(arrowsP2[1])
            my.accelerateBackward();
        if(arrowsP2[2])
            my.moveRight();
        if(arrowsP2[3])
            my.moveLeft();
    }

    // NPC movement
    updateOthers();

    for(int i = 0; i < NUM_KARTS; i++)
    {

        karts[i]->setVelocity(
            karts[i]->getVelX()+karts[i]->getAccX(),
            karts[i]->getVelZ()+karts[i]->getAccZ()
        );

        karts[i]->setPositionPoint(
            karts[i]->getPosX()+karts[i]->getVelX(),
            karts[i]->getPosY(),
            karts[i]->getPosZ()+karts[i]->getVelZ()
        );

        karts[i]->setAcceleration(
            -karts[i]->getVelX()*0.015f,
            -karts[i]->getVelZ()*0.015f
        );

        float magnitude = sqrt(karts[i]->getVelX()*karts[i]->getVelX() + karts[i]->getVelZ()*karts[i]->getVelZ());
        if(magnitude >= karts[i]->getStepMagnitude())
        {
            karts[i]->setVelocity(
                karts[i]->getVelX()/magnitude,
                karts[i]->getVelZ()/magnitude
            );
        }
    }
}

void Scene::handleCollisions()
{
    // Handle static collisions

    Kart* current;
    Kart* target;

    float distance;
    float overlap, overlapX, overlapZ;

    float nx, nz, kx, kz, momentum;

    std::vector<std::pair<Kart*,Kart*>> parDeColision;
    std::vector<Kart*> colisionConMuro;

    for(int i = 0; i < NUM_KARTS; i++)
    {
        current = karts[i];
        for(int j = 0; j < NUM_KARTS; j++)
        {
            target = karts[j];
            if(current->getID() != target->getID())
            {
                // Static collision between karts
                if((distance = Util::pointDistance(
                    current->getPosX(),
                    current->getPosY(),
                    current->getPosZ(),
                    target->getPosX(),
                    target->getPosY(),
                    target->getPosZ()
                )) <= current->getRadious() + target->getRadious())
                {
                    parDeColision.push_back({current,target});

                    // Calculate distance to move of the overlap
                    overlap = 0.5f * (distance - current->getRadious() + target->getRadious());

                    // Move circles to a safe position
                    overlapX = overlap * (current->getPosX() - target->getPosX()) / distance;
                    overlapZ = overlap * (current->getPosZ() - target->getPosZ()) / distance;

                    current->setPositionPoint(
                        current->getPosX() + overlapX,
                        current->getPosY(),
                        current->getPosZ() + overlapZ
                    );

                    target->setPositionPoint(
                        target->getPosX() - overlapX,
                        target->getPosY(),
                        target->getPosZ() - overlapZ
                    );
                }
            }
        }

        // Static collision between karts and wall
        if((distance = Util::pointDistance(
            current->getPosX(),
            current->getPosY(),
            current->getPosZ(),
            muro.getX(),
            muro.getY(),
            muro.getZ()
        )) + current->getRadious() >= muro.getRadious())
        {
            colisionConMuro.push_back(current);

            // Calculate overlap between wall and circle
            overlap = current->getRadious() + distance - muro.getRadious();

            // Move circle to a safe place
            current->setPositionPoint(
                current->getPosX() - overlap * (current->getPosX() - muro.getX()) / distance,
                current->getPosY(),
                current->getPosZ() - overlap * (current->getPosZ() - muro.getZ()) / distance
            );
        }
    }

    // Handle dynamic collisions

    // Dynamic collision between karts
    for(unsigned i = 0; i < parDeColision.size(); i++)
    {
        current = parDeColision[i].first;
        target = parDeColision[i].second;

        distance = Util::pointDistance(
            current->getPosX(),
            current->getPosY(),
            current->getPosZ(),
            target->getPosX(),
            target->getPosY(),
            target->getPosZ()
        );

        nx = (target->getPosX() - current->getPosX()) / distance;
        nz = (target->getPosZ() - current->getPosZ()) / distance;

        kx = (current->getVelX() - target->getVelX());
        kz = (current->getVelZ() - target->getVelZ());
        momentum = 2.0f * (nx * kx + nz * kz) / (current->getMass() + target->getMass());

        current->setVelX(current->getVelX() - momentum*target->getMass()*nx);
        current->setVelZ(current->getVelZ() - momentum*target->getMass()*nz);

        target->setVelX(target->getVelX() + momentum*current->getMass()*nx);
        target->setVelZ(target->getVelZ() + momentum*current->getMass()*nz);
    }

    // Dynamic collision between karts and wall
    for(unsigned i = 0; i < colisionConMuro.size(); i++)
    {
        current = colisionConMuro[i];

        distance = Util::pointDistance(
            current->getPosX(),
            current->getPosY(),
            current->getPosZ(),
            muro.getX(),
            muro.getY(),
            muro.getZ()
        );

        nx = (muro.getX() - current->getPosX()) / distance;
        nz = (muro.getZ() - current->getPosZ()) / distance;

        kx = current->getVelX();
        kz = current->getVelZ();
        momentum = 2.0f * (nx * kx + nz * kz) / (current->getMass());

        current->setVelX(current->getVelX() - momentum*current->getMass()*nx);
        current->setVelZ(current->getVelZ() - momentum*current->getMass()*nz);
    }
}

void Scene::setFullViewport()
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY,(float)w/h,ZNEAR,ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::setHalfViewport(int w0, int h0)
{
    glViewport(w0, h0, w, h/2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY,(float)w/(h/2),ZNEAR,ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::draw(Kart *kart)
{
    glPushMatrix();

    glLoadIdentity();
    cam.set(
        kart->getPosX(),
        kart->getPosY()+0.75f,
        kart->getPosZ(),
        kart->getDirX(),
        kart->getDirY(),
        kart->getDirZ(),
        0.0f,1.0f,0.0f
    );
    cam.display();

    glPushMatrix();

    glPushMatrix();

    sky.set(kart->getPosX(),sky.getY(),kart->getPosZ());
    sky.draw();

    muro.draw();
    piso.draw();

    glPopMatrix();

    for(int i = 0; i < NUM_KARTS; i++)
        karts[i]->draw();

    glPopMatrix();

    glPopMatrix();
}

void Scene::display()
{
    updateMovement();
    handleCollisions();
    if(player)
    {
        setFullViewport();
        draw(&mx);
    }
    else
    {
        setHalfViewport(0,h/2);
        draw(&mx);
        setHalfViewport(0,0);
        draw(&my);
    }
}

void Scene::setSize(int w, int h)
{
    this->w = w; this->h = h;
}
