
#pragma once

// ivp_solver.h
#include <iostream>
#include <valarray>
#include <functional>


// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());

    // time loop
    for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*dsdt; // Euler

        // write new state
        writer(s, t);
      }
}

template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer){

      system_t dsdt(s.size());
      system_t k_2(s.size());

      for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t); 
        fderiv(s + (tinit*dsdt), k_2, t + tinit);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + ((tinit/2)*(dsdt + k_2)); // Euler

        // write new state
        writer(s, t);
      }
}