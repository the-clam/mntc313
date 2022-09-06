clear all
clc

prompt = 'Enter values: '; % [15,16;13,4;20,21;...]
coordinates = input(prompt);
N=12;
for i = 1:1:N-1
    if (i == (N)) %No comma after last value in a row
        fprintf("(%0.1f,%0.1f)\n", coordinates(i,1), coordinates(i,2));
    elseif(i == N/2) %No comma after last value in a row
        fprintf("(%0.1f,%0.1f),\n", coordinates(i,1), coordinates(i,2));
    else
        fprintf("(%0.1f,%0.1f),", coordinates(i,1), coordinates(i,2));
    end
end

fprintf("\n");
fprintf("Average center: (%0.1f,%0.1f)\n\n",mean(coordinates,1));

DistMatrix = pdist2(coordinates,coordinates);

for i = 1:1:N
    fprintf("Distance from point %d to\n",i);
    for j = 1:N
        if (j == N)
            fprintf("%d.- %0.1f\n",j,DistMatrix(i,j));        else
            fprintf("%d.- %0.1f, ",j, DistMatrix(i,j));
        end
    end
end

fprintf("\n");

for i = 1:N
	fprintf("Average distance from point %d: %0.1f km\n", i, sum(DistMatrix(:,i)/(N-1)));
end
