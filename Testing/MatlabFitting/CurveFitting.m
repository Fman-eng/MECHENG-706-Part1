%Requires the curve fitting toolbox to be installed


clc;
clear;
[Sensor1,Distance1,Sensor3,Distance3] = readvars('IRSensorTesting.xlsx');

%Select a two term, exponential fit to get correct values.
cftool(Sensor1,Distance1);

cftool(Sensor3,Distance3);