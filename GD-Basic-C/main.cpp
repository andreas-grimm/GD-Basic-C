//
//  main.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include <iostream>
#include "helper/common.hpp"
#include "helper/logger.hpp"
#include "helper/command_line.hpp"
#include "helper/printer.hpp"
#include "helper/error_codes.hpp"
#include "basic.hpp"
#include "memoryManager/memory.hpp"

int main(int argc, char *argv[]) {
    
    Logger *poLogger = Logger::getInstance();
    Printer oPrinter;
    CommandLine *poCommandLine = new CommandLine(argc, argv);
    Basic *poBasic;
    Memory *poMemory = new Memory();
    
    string strLogLevel = "";
    string strBasicFile = "";
    string strBasicFileLogMessage ="Program file to be processed ";
    int iErrorCode = OK;
    int64_t llMemory = poMemory->getTotalMemory() / 1024000000;
   
    // process the command line
    if (poCommandLine->containsLogLevel() == YES) {
        strLogLevel = poCommandLine->getLogLevel();
    }
    poLogger->setLogLevel(strLogLevel);

    if (poCommandLine->containsQuiet() == NO) {
        oPrinter.println();
        oPrinter.println("   _____ _____             ____            _    ");
        oPrinter.println("  / ____|  __ \\           |  _ \\          (_)        GriCom Basic Interpreter Version 0.1.0 (C++ Version)");
        oPrinter.println(" | |  __| |  | |  ______  | |_) | __ _ ___ _  ___    (c) Copyright A.Grimm 2023");
        oPrinter.println(" | | |_ | |  | | |______| |  _ < / _` / __| |/ __|   ");
        oPrinter.println(" | |__| | |__| |          | |_) | (_| \\__ \\ | (__    Free memory: " + to_string(llMemory) + " GBytes");
        oPrinter.println("  \\_____|_____/           |____/ \\__,_|___/_|\\___| ");
        oPrinter.println();
    }

    if (poCommandLine->containsInputFile() == NO) {
        poLogger->error("main", "Program file name missing...");
        oPrinter.println("");
        oPrinter.println("usage: gw-basic-c <filename.bas>");
        oPrinter.println("where <filename.bas> is a relative path to a .bas program to run.");
        return ERR_MISSING_PROGRAM_FILE;
    } else {
        strBasicFile = poCommandLine->getInputFile();
        poLogger->info("main", "Program file: " + strBasicFile);
    }
    
    // here we call the interpreter
    poBasic = new Basic(strLogLevel);
    iErrorCode = poBasic->interpret(strBasicFile);
    
    // let's clean up...
    delete poCommandLine;
    
    return iErrorCode;
}
