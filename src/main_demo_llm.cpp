//
// Created by 69029 on 4/12/2021.
//

#undef NDEBUG
#include "circuit.h"
#include "neuralNetwork.hpp"
#include "verifier.hpp"
#include "models.hpp"
#include "global_var.hpp"
#include <iostream>
#include "zkGPT_bindings.hpp"
#include "logger.hpp"
#include "llama.hpp"

using namespace mcl::bn;
using namespace std;




int main(int argc, char **argv) 
{
    // Initialize zkGPT bindings
    init_zkGPT_bindings();
    logger::start_measure();

    // Load LLM model
    LlamaModel model = load_llm_model("path/to/model");
    logger::log_measure("Model Loaded");

    // Verify integrity with zkGPT
    if (!verify_integrity()) {
        logger::log_measure("Integrity Check Failed");
        return -1;
    }
    logger::log_measure("Integrity Verified");

    // Setup secure communication
    secure_communication();
    logger::log_measure("Secure Communication Setup");

    // Run LLM inference
    auto results = model.run_inference();
    logger::log_measure("Inference Completed");

    // Output results
    std::cout << "Inference Results: " << results << std::endl;
    logger::log_measure("Results Output");

    logger::log_measure("Process Completed");
    return 0;
}

