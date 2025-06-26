const common = require("../common.js");

const component_file_list = [
    "source/pru_i2s/.project/project.js"
];

const device_defines = {
    common: [
        "SOC_AM263X",
    ],
};

const example_file_list = [
    /*NOTE: Always add PRU firware project first to ensure R5F picks latest firmware header when all examples are built at once using makefile*/
    "examples/empty/firmware/.project/project.js",
    "examples/empty/.project/project.js"
    "examples/pru_i2s_diagnostic/single_channel/.project/project.js",
    "source/pru_i2s/firmware/TDM4/pru0_tx/.project/project.js",
    "source/pru_i2s/firmware/TDM4/pru1_rx/.project/project.js",
    "source/pru_i2s/firmware/I2S/pru0_tx/.project/project.js",
    "source/pru_i2s/firmware/I2S/pru1_rx/.project/project.js",
];

function getProjectSpecCpu(cpu) {
    let projectSpecCpu =
    {
        "r5fss0-0": "Cortex_R5_0",
        "r5fss0-1": "Cortex_R5_1",
        "r5fss1-0": "Cortex_R5_2",
        "r5fss1-1": "Cortex_R5_3",
        "icss_m0_pru0": "ICSSM_PRU_0",
        "icss_m0_pru1": "ICSSM_PRU_1",
    }

    return projectSpecCpu[cpu];
}

function getComponentList() {
    return component_file_list;
}

function getExampleList() {
    return example_file_list;
}

function getSysCfgDevice(board) {
    switch (board) {
        case "am263x-lp":
            return "AM263x_beta";
        default:
        case "am263x-cc":
            return "AM263x_beta";
    }
}

function getProjectSpecDevice(board) {
    switch (board) {
        case "am263x":
            return "AM263x";
        case "am263x-lp":
            return "AM263x";
        default:
        case "am263x-cc":
            return "AM263x";
    }
}

function getSysCfgCpu(cpu) {
    return cpu;
}

function getSysCfgPkg(board) {
    switch (board) {
        case "am263x-lp":
            return "ZCZ";
        default:
        case "am263x-cc":
            return "ZCZ";
    }
}

function getSysCfgPart(board) {
    switch (board) {
        case "am263x-lp":
            return "AM263x";
        default:
        case "am263x-cc":
            return "AM263x";
    }
}

function getDevToolTirex(board) {
    switch (board) {
        case "am263x-lp":
            return "LP-AM263";
        default:
        case "am263x-cc":
            return "TMDSCNCD263";
    }
}

function getProperty() {
    let property = {};

    property.defines = device_defines;

    return property;
}

function getLinuxFwName(cpu) {

    switch(cpu) {
        case "r5fss0-0":
            return "am263-main-r5f0_0-fw";
        case "r5fss0-1":
            return "am263-main-r5f0_1-fw";
        case "r5fss1-0":
            return "am263-main-r5f1_0-fw";
        case "r5fss1-1":
            return "am263-main-r5f1_1-fw";
    }
    return undefined;
}

function getDependentProductNameProjectSpec() {
    return "MCU_PLUS_SDK_AM263X";
}

function getFlashAddr() {
    return 0x60000000;
}

module.exports = {
    getComponentList,
    getExampleList,
    getSysCfgDevice,
    getSysCfgCpu,
    getSysCfgPkg,
    getSysCfgPart,
    getProjectSpecDevice,
    getProjectSpecCpu,
    getDevToolTirex,
    getProperty,
    getLinuxFwName,
    getDependentProductNameProjectSpec,
    getFlashAddr,
};
