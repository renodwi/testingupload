new
    Float:vehicle_fuel[MAX_VEHICLES],
    Float:vehicle_max_fuel[MAX_VEHICLES],
    
    bool:vehicle_consuming_fuel[MAX_VEHICLES],
    vehicle_consume_fuel_timer[MAX_VEHICLES],
    Float:last_vehicle_position[MAX_VEHICLES][3],
    
    bool:vehicle_refueling[MAX_VEHICLES],
    Float:vehicle_refueling_amount[MAX_VEHICLES],
    vehicle_refueling_timer[MAX_VEHICLES];