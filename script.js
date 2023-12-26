document.addEventListener("DOMContentLoaded", () => {
    const weatherContainer = document.getElementById("weather-container");

    fetch("http://localhost:8080/weather")
        .then(response => response.json())
        .then(data => {
            for (const city in data) {
                const temperature = data[city].temperature;
                const cityElement = document.createElement("div");
                cityElement.innerHTML = `<p>${city}: ${temperature}°C</p>`;
                weatherContainer.appendChild(cityElement);
            }
        })
        .catch(error => console.error("Error fetching weather data:", error));
});
