// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyAeBtt46yFj0a_qxkWt9gMNtwD3SlBRS-4",
  authDomain: "react-exam-ac2c2.firebaseapp.com",
  projectId: "react-exam-ac2c2",
  storageBucket: "react-exam-ac2c2.firebasestorage.app",
  messagingSenderId: "110678535419",
  appId: "1:110678535419:web:3c48ae1153b48fc736945e",
  measurementId: "G-B8SDRMTRK6"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);