import re
import requests
from flask import Flask, request, jsonify
from flask_cors import CORS
import json

# New imports for OCR and HTML parsing
import pytesseract
from PIL import Image
from bs4 import BeautifulSoup
import io

app = Flask(__name__)  # Correct Flask app initialization
CORS(app)

# Your API Key (consider using an environment variable for security)
OPENROUTER_API_KEY = "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"

modelR1 = "deepseek/deepseek-r1:free"
modelV1 = "deepseek/deepseek-chat:free"
model7B = "mistralai/mistral-7b-instruct:free"
model70B = "deepseek/deepseek-r1-distill-llama-70b:free"

BASEURL = "https://openrouter.ai/api/v1/chat/completions"


def checkCondition(query, model):
    try:
        response = requests.post(
            BASEURL,
            headers={
                "Authorization": f"Bearer {OPENROUTER_API_KEY}",
                "Content-Type": "application/json"
            },
            json={
                "model": model,
                "messages": [
                    {"role": "system", "content": "You are a classification bot. Only return the category number."},
                    {"role": "user", "content": f"""Categorize the following query into one of the categories below.  
            
            Query: "{query}"  
            
            Categories:  
            1 - General Medical Query  
            2 - Medical Symptoms  
            3 - Non-Medical  
            
            Respond with only the category number (1, 2, or 3). Do not add any extra text."""}
                ],
            },
        )
        response_json = response.json()
        return response_json["choices"][0]["message"]["content"].strip().lower()
    
    except Exception as e:
        print(f"Error in checkCondition: {e}")
        return "error"
    

def genResponse(query, context='None', queryCategory="1", model=model7B):
    if queryCategory == "2":
        sysContent = "You are an AI Health assistant providing structured responses by analysing the context."
        userContent = "Analyse the context and provide a detailed analysis and solution for the query."
        context = f"Context: {context}"
        format_str = """Give response in following format:
            <Possible health issue>
            <probability>
            <severity level>
            <Possible cause>
            <Possible solution>
            <recommended action>
            
            Constraints: Give the response in dict format"""
    else:
        sysContent = "You are an AI Health assistant providing structured responses for the query."
        userContent = "Provide a detailed analysis and solution for the query."
        context = ""
        format_str = ""
            
    try:
        response = requests.post(
            BASEURL,
            headers={
                "Authorization": f"Bearer {OPENROUTER_API_KEY}",
                "Content-Type": "application/json"
            },
            json={
                "model": model,
                "messages": [
                    {"role": "system", "content": sysContent},
                    {"role": "user",
                     "content": f"{userContent}\nquery: {query}\n{context}\n" + format_str}
                ],
            },
        )
        response_json = response.json()
        return response_json["choices"][0]["message"]["content"].strip()
    except Exception as e:
        print(f"Error in genResponse: {e}")
        return "I'm sorry, I couldn't generate a response."


def genMedicalHistoryQues(query, model):
    medHistoryTemplate = """category 1. History of Present Illness (HPI) (Use the OLD CARTS or PQRST method):
                        Onset: When did the symptoms start?
                        Location: Where do you feel the pain or discomfort?
                        Duration: How long have you had this issue?
                        Character: Can you describe the symptom? (e.g., sharp, dull, burning)
                        Aggravating/Alleviating Factors: "What makes it worse or better?"
                        Radiation: Does the pain or discomfort spread anywhere?
                        Timing: Is it constant or does it come and go?
                        Severity: On a scale of 1-10, how severe is it?

                        category 2. Past Medical History (PMH):
                        Do you have any existing medical conditions?
                        Have you been diagnosed with any chronic illnesses (e.g., diabetes, hypertension)?
                        Have you had any surgeries or hospitalizations in the past?
                        Have you had any major infections or illnesses before?

                        category 3. Medications & Allergies:
                        Are you currently taking any medications, including over-the-counter or supplements?
                        Do you have any known drug, food, or environmental allergies?

                        category 4. Family History (FH):
                        Does anyone in your family have a history of chronic illnesses like diabetes, heart disease, or cancer?
                        Has anyone in your family had similar symptoms or conditions?
                        """
                        
    try:
        response = requests.post(
            BASEURL,
            headers={
                "Authorization": f"Bearer {OPENROUTER_API_KEY}",
                "Content-Type": "application/json"
            },
            json={
                "model": model,
                "messages": [{
                    "role": "user",
                    "content": f"""Query: {query},
                        Modify and give all the medical-history questions that are relevant to this query, from this set of medical-history questions:
                        
                        Medical-history Questions:
                        {medHistoryTemplate}
                        
                        Give response in this format:
                        <Question 1>
                        <Question 2>
                        <Question 3>
                        ...
                        
                        Constrains: Do not generate any other text other than the questions.
                        """
                }]
            },
        )
        return response.json()["choices"][0]["message"]["content"].strip().split('\n')
    except Exception as e:
        print(f"Error in genMedicalHistoryQues: {e}")
        return []
    
    
def getUserResponses():
    dummy_responses = [
        # Category 1: History of Present Illness (HPI)
        "I first experienced these migraines about 2 years ago.",
        "I feel the migraine pain mostly on one side of my head, sometimes behind my eyes.",
        "I've been experiencing these migraines on and off for the past 2 years.",
        "The migraine feels like a throbbing, pulsating pain.",
        "Stress and lack of sleep seem to trigger my migraines, while rest and hydration help alleviate them.",
        "Yes, sometimes the pain spreads to my neck and shoulders.",
        "They come and go, usually lasting for a few hours.",
        "I would rate the severity of my migraines around 7 out of 10.",

        # Category 2: Past Medical History (PMH)
        "I have no chronic illnesses, but I do have occasional tension headaches.",
        "No, I have never had any surgeries or hospitalizations related to migraines or other health issues.",
        "No major infections or illnesses that I can recall.",

        # Category 3: Medications & Allergies
        "I sometimes take over-the-counter painkillers like ibuprofen when the migraine is severe.",
        "I have no known drug, food, or environmental allergies.",

        # Category 4: Family History (FH)
        "Yes, my father has hypertension, and my mother has diabetes.",
        "Yes, my mother also experiences migraines occasionally."
    ]
    return dummy_responses

    
def getRealTimeData():
    normalData = {
        "timestamp": "2025-02-25 10:05:00",
        "heart_rate_bpm": 110,
        "spo2_percentage": 95,
        "body_temperature_c": 36.9,
        "steps": 650,
        "calories_burned": 35,
        "stress_level": 8,
        "sleep_hours": 6.5,
        "blood_pressure_mmHg": "100/95",
        "irregular_heartbeat": False
    }
    
    health_alert = {
        "timestamp": "2025-02-25 11:30:00",
        "heart_rate_bpm": 135,
        "spo2_percentage": 92,
        "body_temperature_c": 37.2,
        "steps": 300,
        "calories_burned": 15,
        "stress_level": 9,
        "sleep_hours": 4.0,
        "blood_pressure_mmHg": "150/95",
        "irregular_heartbeat": True,
    }
    return json.dumps(normalData, indent=4)


def mergeFollowupsResponse(medicalHistoryQues, userResponses, RealTimeData):
    context = ""
    for i, (question, response) in enumerate(zip(medicalHistoryQues, userResponses)):
        question_text = question.split(".", 1)[-1].strip()  # Use only the part after the first period
        context += f"Follow-up {i + 1}: {question_text}. Response: {response}\n"
    context += f"\nReal-Time Data:\n{RealTimeData}\n"
    return context


# ----------------- New Functions for Medicine Details from an Image -----------------

def determineBestItem(medicine_name, item_names):
    """
    Uses the Mistral 7B API to select the best matching medicine item.
    """
    prompt = f"Among the following items: {', '.join(item_names)}, which is the best option for the medicine '{medicine_name}'? Respond with only the item name."
    try:
        response = requests.post(
            BASEURL,
            headers={
                "Authorization": f"Bearer {OPENROUTER_API_KEY}",
                "Content-Type": "application/json"
            },
            json={
                "model": model7B,
                "messages": [
                    {"role": "system", "content": "You are an assistant that selects the best matching medicine from a list."},
                    {"role": "user", "content": prompt}
                ],
            },
        )
        best_item = response.json()["choices"][0]["message"]["content"].strip()
        return best_item
    except Exception as e:
        print(f"Error in determineBestItem: {e}")
        return None


def getDrugHeaderFromURL(url):
    """
    Fetches the webpage at the provided URL and extracts the text from the HTML element with id 'drug-main-header'.
    """
    try:
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        header_elem = soup.find(id="drug-main-header")
        if header_elem:
            return header_elem.get_text(separator=" ", strip=True)
        else:
            return None
    except Exception as e:
        print(f"Error in getDrugHeaderFromURL: {e}")
        return None


def getMedicineDetailsFromImage(image_file):
    """
    Process an image to extract the medicine name, search 1mg for items, determine the best matching item,
    and extract detailed information from its page using the LLM.
    """
    # Step 1: Extract text (medicine name) from the image using OCR.
    try:
        image = Image.open(image_file.stream)
    except Exception as e:
        print(f"Error opening image: {e}")
        return {"error": "Invalid image file."}
    
    extracted_text = pytesseract.image_to_string(image).strip()
    # Assume the first non-empty line is the medicine name.
    medicine_name = next((line for line in extracted_text.split('\n') if line.strip()), None)
    if not medicine_name:
        return {"error": "Could not extract medicine name from image."}
    
    # Step 2: Search the medicine name on 1mg.
    search_url = f"https://www.1mg.com/search/all?name={medicine_name}"
    try:
        search_response = requests.get(search_url)
        soup = BeautifulSoup(search_response.text, 'html.parser')
        # Step 3: Extract first 10 item names (adjust the tag/class as per 1mg's structure).
        items = soup.find_all("div", class_="drug-item")
        item_names = [item.get_text(strip=True) for item in items[:10]]
        if not item_names:
            return {"error": "No items found on 1mg site."}
    except Exception as e:
        print(f"Error searching 1mg: {e}")
        return {"error": "Error searching the 1mg site."}
    
    # Step 4: Determine the best matching item using the Mistral 7B API.
    best_item = determineBestItem(medicine_name, item_names)
    if not best_item:
        return {"error": "Could not determine the best item."}
    
    # Step 5: Construct the URL for the best item (assumes a URL pattern; adjust if necessary).
    best_item_slug = best_item.replace(" ", "-").lower()
    item_url = f"https://www.1mg.com/drugs/{best_item_slug}"
    
    # Step 6: Retrieve the drug header text from the item page.
    header_text = getDrugHeaderFromURL(item_url)
    if not header_text:
        return {"error": "Could not extract drug header from the item page."}
    
    # Step 7: Use the LLM to extract key details from the header text.
    query_for_llm = f"Extract the key details from the following drug header information:\n{header_text}"
    final_details = genResponse(query_for_llm, queryCategory="2", model=model7B)
    
    return {
        "medicine_name_extracted": medicine_name,
        "search_results": item_names,
        "best_item": best_item,
        "item_url": item_url,
        "drug_header": header_text,
        "final_details": final_details
    }

# ----------------- Existing Endpoints -----------------

@app.route('/ask', methods=['POST'])
def ask():
    data = request.json
    query = data.get("query", "").strip()

    if not query:
        return jsonify({"error": "No query provided"}), 400

    # Checking query category
    category = checkCondition(query, model7B)
    medicalHistoryQues = None
    response = ''
    
    if "1" in category:
        response = genResponse(query, queryCategory="1", model=model7B)
    elif "2" in category:
        medicalHistoryQues = genMedicalHistoryQues(query, model7B)
        response = genResponse(query, queryCategory="1", model=model7B)
        return jsonify({"query": query, "response": response, "followups": medicalHistoryQues})
    else:
        return jsonify({"response": "I am sorry, I can only respond to medical-related queries!"})
    
    return jsonify({"query": query, "response": response})


@app.route('/answer', methods=['POST'])
def answer():
    data = request.json
    medicalHistoryQues = data.get("followups", [])
    userResponses = data.get("responses", [])
    RealTimeData = getRealTimeData()

    if not medicalHistoryQues or not userResponses:
        return jsonify({"error": "Missing follow-up questions or responses."}), 400

    context = mergeFollowupsResponse(medicalHistoryQues, userResponses, RealTimeData)
    query = "Analyse the context and give detailed response in the stated format."
    final_response = genResponse(query, context=context, queryCategory="2", model=model7B)

    return jsonify({"final_response": final_response})


# ----------------- New Endpoint for Image Processing -----------------

@app.route('/medicine-details', methods=['POST'])
def medicine_details():
    if 'image' not in request.files:
        return jsonify({"error": "No image file provided."}), 400
    image_file = request.files['image']
    if image_file.filename == "":
        return jsonify({"error": "No selected file."}), 400
    result = getMedicineDetailsFromImage(image_file)
    return jsonify(result)


if __name__ == '__main__':
    app.run(debug=True, port=5001)
