#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "circuit.h"
#include "hyrax.hpp"
#include "prover.hpp"

namespace py = pybind11;

PYBIND11_MODULE(zkGPT_bindings, m) {
    m.doc() = "Python bindings for zkGPT C++ functions";

    // Expose circuit initialization functions
    m.def("init_circuit", &layeredCircuit::init, "Initialize the circuit with given parameters");

    // Expose cryptographic functions
    m.def("perdersen_commit", &perdersen_commit, "Perform a Pedersen commitment");
    m.def("prove_dot_product", &prove_dot_product, "Prove a dot product using zkGPT");

    // Expose prover functions
    m.def("sumcheck_init_all", &prover::sumcheckInitAll, "Initialize sumcheck for all layers");
    m.def("commit_input", &prover::commitInput, "Commit input values for proof generation");

    // Expose additional functions for integrity and security checks
    m.def("verify_integrity", &prover::verifyIntegrity, "Verify the integrity of the LLM process");
    m.def("secure_communication", &hyrax::secureCommunication, "Ensure secure communication between LLM and zkGPT");

    // Add more bindings as needed for other functions
}
