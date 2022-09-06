classdef multiCenters %define class
    properties
        numCustomers; %define fields
        avItemPrice;
        avKgTransported;
        costPerTransporKG;
    end
    methods
        function obj = multiCenters(nCustomers, aIPrice, aKTransported, cPTransporKG) %create object
            obj.numCustomers = nCustomers;
            obj.avItemPrice = aIPrice;
            obj.avKgTransported = aKTransported;
            obj.costPerTransporKG = cPTransporKG;
        end
        function [customersServed, weightTransported, revenue] = totals(obj) %create methods
            customersServed = sum(obj.numCustomers);
            weightTransported = sum(obj.avKgTransported.*obj.numCustomers);
            revenue = sum(obj.numCustomers.*obj.avItemPrice-obj.numCustomers.*obj.avKgTransported.*obj.costPerTransporKG);
        end            
    end
end
        