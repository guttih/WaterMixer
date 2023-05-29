#include <iostream>
#include <chrono>
#include <cmath>

unsigned long nowMs()
{
    auto sysTime = std::chrono::system_clock::now();
    return (unsigned long)std::chrono::duration_cast<std::chrono::milliseconds>(sysTime.time_since_epoch()).count();
}

void sleepMilliseconds(int milliseconds)
{
    unsigned long x = nowMs();
    while (nowMs() < x + milliseconds)
    {
        continue;
    }
}

// #include <cmath> // Include the <cmath> header for std::abs

class PIDSimulator
{
private:
    double current;
    double target;
    double kp;
    double ki;
    double kd;
    double integral;
    double previous_error;
    double dt;

public:
    PIDSimulator(double initial, double target, double kp, double ki, double kd, double dt)
        : current(initial), target(target), kp(kp), ki(ki), kd(kd), dt(dt),
          integral(0), previous_error(0) {}

    void update()
    {
        // Calculate the error between the target and current value
        double error = target - current;

        // Calculate the integral term by accumulating the error over time
        integral += error * dt;

        // Calculate the derivative term by measuring the rate of change of the error
        double derivative = (error - previous_error) / dt;

        // Calculate the output using the PID control formula
        double output = kp * error + ki * integral + kd * derivative;

        // Update the current value by applying the output
        current += output;

        // Update the previous error for the next iteration
        previous_error = error;
        printf("derivative: %+8.2f output: %+8.2f  ", derivative, output);
    }
    void simulate()
    {
        while (std::abs(current - target) > 0.01)
        {
            update();

            sleepMilliseconds(100);

            printf("Current: %+8.2f Error: %+8.2f  \n", current, (current - target));
        }

        std::cout << "Simulation finished. Current value reached target." << std::endl;
    }
};

int main()
{
    double initial = 0.0;
    double target = 10.0;
    double kp = 0.1;
    double ki = 0.1;
    double kd = 0.1;
    double dt = 0.1;
    PIDSimulator simulator(initial, target, kp, ki, kd, dt);
    simulator.simulate();

    return 0;
}
