clear all
clc

g = 9.81;

prompt = 'Enter time, initial velocity, initial angle and initial heigth: ';
data = input(prompt, 's');
data = sscanf(data, '%f');
time = data(1, :);
initVel = data(2, :);
initAng = data(3, :);
initH = data(4, :);

currentH = -(1/2)*g*time*time + initVel*sin(pi*initAng/180)*time + initH;
currentVel = -g*time + initVel*sin(pi*initAng/180);


if (time > 0)
	fprintf("Projectile released\n");
	fprintf('Position: %0.2f meters\n', currentH);
	fprintf('Velocity value: %0.2f meters/second\n', currentVel);
	if (currentVel >= 0)
		fprintf("Projectile ascending\n");
		if (currentH >= initH)
			fprintf("Projectile above initial position\n");
		else
			fprintf("Projectile below initial position\n");
		end
	else
		fprintf("Projectile descending\n");			
		if (currentH >= initH)
			fprintf("Projectile above initial position\n");
		else
			fprintf("Projectile below initial position\n");
		end
	end
else
	fprintf("Projectile not released\n");
end
