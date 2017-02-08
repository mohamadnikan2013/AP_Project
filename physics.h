#ifndef PHYSICS_H
#define PHYSICS_H

class Physics
{
private:
    double v;
    double a;
    double maxV;
    double minV;
    int accelerattionFrames;


    static int fps;
public:
    Physics(double v = 0, double a = 0, double maxV = 999999999, double minV = 0);
    double getV() const;
    void setV(double value);
    double getA() const;
    void setA(double value);
    void accelerate(int x);
    int getAccelerattionFrames() const;

    double movement();

    static int getFps();
    static void setFps(int value);
    double getMaxV() const;
    void setMaxV(double value);
    double getMinV() const;
    void setMinV(double value);
};

#endif // PHYSICS_H
