%Version A
function stressCalc(elasticMod, strain)
maxComp = 30;
maxTen = 5;
stress = elasticMod*strain;
fprintf('Stress value: %0.2f MPa\n', stress);

if stress > 0
    fprintf('Bridge deck in tension\n');
    
    if abs(stress) > maxTen
        fprintf('Danger: tensile strength exceeded\n');
    else
        fprintf('Bridge deck safe\n');
    end
elseif stress < 0
    fprintf('Bridge deck in compression\n');
    
    if abs(stress) > maxComp
        fprintf('Danger: compressive strength exceeded\n');
    else
        fprintf('Bridge deck safe\n');
    end
else
    fprintf('No stress in bridge\n');
end

end