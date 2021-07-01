import { StatusBar } from 'expo-status-bar';
import React from 'react';
import { Text, TextInput, View, TouchableOpacity } from 'react-native';
import { texts, add_post } from './styles'
import Icon_Cross from 'react-native-vector-icons/Entypo'
import RNUrlPreview from 'react-native-url-preview';

const DisplayContent = () => {
    const [link, onChangeText] = React.useState('');
    return (
        <View style={add_post.container}>
            <TextInput style={add_post.search_bar} placeholder="Rechercher un article par nom ou lien" onChangeText={link => onChangeText(link)} />
            <TextInput style={add_post.search_bar} placeholder="Rechercher un thème" />
            <TextInput style={add_post.search_bar} placeholder="Rechercher une catégorie" />
            <RNUrlPreview text={link} />
            <TextInput style={add_post.description_bar} placeholder='Description' />
            <TextInput style={add_post.search_bar} placeholder='Tags' />
            <TouchableOpacity style={add_post.publish_opacity}>
                <Text style={add_post.publish_text}>Publier</Text>
            </TouchableOpacity>
        </View>
    )
};

export default class MyAddPage extends React.Component {
    render() {
        return (
            <View style={{ flex: 1 }}>
                <View style={add_post.top_bar}>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center', paddingTop: 25 }}>
                        <TouchableOpacity onPress={() => this.props.navigation.goBack()}>
                            <Icon_Cross name="cross" size={32} color="#5A5A5A" />
                        </TouchableOpacity>
                    </View>
                    <View style={{ flex: 4, alignItems: 'center', justifyContent: 'center', paddingTop: 25 }}>
                        <Text style={texts.title_of_page}>Nouveau post</Text>
                    </View>
                </View>
                <DisplayContent />
                <StatusBar style="auto" />
            </View >
        )
    }
}