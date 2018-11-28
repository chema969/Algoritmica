#include "Mochila.hpp"

bool Mochila::insertarMaterial(Material m){
                          if((pesoActual_+m.getCantidad())>capacidad_)return false;
                          pesoActual_+=m.getCantidad();
                          for (std::vector<Material>::iterator it = mat_.begin() ; it != mat_.end(); ++it){
                                               if(m.getPrecio()<it->getPrecio()){
                                                      mat_.insert(it,m);return true;
                                                }                        
                          }
                          mat_.push_back(m); return true;
                         }
