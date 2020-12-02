plugins {
    java
    application
    id("com.github.johnrengelman.shadow") version "5.2.0"
}

repositories {
    jcenter()
}

val javaFXModules = listOf(
    "base",
    "controls",
    "fxml",
    "swing",
    "graphics"
)

val supportedPlatforms = listOf("linux", "mac", "win")

dependencies {
    for (platform in supportedPlatforms) {
        for (module in javaFXModules) {
            implementation("org.openjfx:javafx-$module:13:$platform")
        }
    }
    
    // https://mvnrepository.com/artifact/org.scream3r/jssc
	//compile group: 'org.scream3r', name: 'jssc', version: '2.8.0'
    implementation("org.scream3r:jssc:2.8.0")
}

tasks.withType<Test> {
    // Enables JUnit 5 Jupiter module
    useJUnitPlatform()
}

application {
    mainClassName = "application.Launcher"
}
